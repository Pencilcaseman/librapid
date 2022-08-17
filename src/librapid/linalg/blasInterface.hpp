#pragma once

#include "../internal/config.hpp"
#include "../array/helpers/kernelHelper.hpp"
#include "../array/helpers/kernelFormat.hpp"
#include "../internal/memUtils.hpp"
#include "../cuda/memUtils.hpp"
#include "../modified/modified.hpp"

namespace librapid::blas {
	template<typename A, typename B>
	using Common = typename std::common_type_t<A, B>;

	template<typename Device, typename A, typename B>
	LR_INLINE Common<A, B> dot(int64_t n, A *__restrict x, int64_t incX, B *__restrict y,
							   int64_t incY) {
		if constexpr (std::is_same_v<Device, device::CPU>) {
			Common<A, B> res(0);
			for (int64_t i = 0; i < n; i++) res += x[i * incX] * y[i * incY];
			return res;
		}
#if defined(LIBRAPID_HAS_CUDA)
		else {
			using jitify::reflection::Type;

			int64_t threadsPerBlock, blocksPerGrid;
			// Use 1 to 512 threads per block
			if (n < 512) {
				threadsPerBlock = n;
				blocksPerGrid	= 1;
			} else {
				threadsPerBlock = 512;
				blocksPerGrid	= ceil(double(n) / double(threadsPerBlock));
			}

			std::string opKernel =
			  fmt::format("#define BLOCK_SIZE {}\n", threadsPerBlock) + R"V0G0N(
template<typename A, typename B, typename C>
__global__
void dot(int64_t n, A *__restrict x, int64_t incX, B *__restrict y, int64_t incY, C *__restrict dst) {
	__shared__ C cache[BLOCK_SIZE];
	int64_t i = blockIdx.x * blockDim.x + threadIdx.x;
	cache[threadIdx.x] = 0;
	while (i < n) {
		cache[threadIdx.x] += x[i * incX] * y[i * incY];
		i += gridDim.x * blockDim.x;
	}
	__syncthreads();  // required because later on the current thread is
					  // accessing data written by another thread
	i = BLOCK_SIZE / 2;
	while (i > 0) {
		if (threadIdx.x < i) cache[threadIdx.x] += cache[threadIdx.x + i];
		__syncthreads();
		i /= 2;  // not sure bitwise operations are actually faster
	}
	#ifndef NO_SYNC  // serialized access to shared data;
		if (threadIdx.x == 0) atomicAdd(dst, cache[0]);
	#else  // no sync, what most likely happens is:
		// 1) all threads read 0
		// 2) all threads write concurrently 16 (local block dot product)
		if (threadIdx.x == 0) *dst += cache[0];
	#endif
}
)V0G0N";

			std::string kernel = detail::kernelGenerator(opKernel);

			static jitify::JitCache kernelCache;
			jitify::Program program = kernelCache.program(kernel, cudaHeaders, nvccOptions);

			dim3 grid(blocksPerGrid);
			dim3 block(threadsPerBlock);

			Common<A, B> *deviceRes = memory::malloc<Common<A, B>, device::GPU>(1);

			jitifyCall(program.kernel("dot")
						 .instantiate(Type<A>(), Type<B>(), Type<Common<A, B>>())
						 .configure(grid, block, 0, memory::cudaStream)
						 .launch(n, x, incX, y, incY, deviceRes));

			Common<A, B> hostRes;
			memory::memcpy<Common<A, B>, device::CPU, Common<A, B>, device::GPU>(
			  &hostRes, deviceRes, 1);
			memory::free<Common<A, B>, device::GPU>(deviceRes);

			return hostRes;
		}
#endif
	}

	template<typename Device, typename A, typename B, typename C>
	LR_INLINE void gemm(bool transA, bool transB, int64_t m, int64_t n, int64_t k, A alpha,
						const A *__restrict a, int64_t lda, const B *__restrict b, int64_t ldb,
						B beta, C *__restrict c, int64_t ldc) {
		if constexpr (std::is_same_v<Device, device::CPU>) {
			// CPU implementation
 #if defined(LIBRAPID_HAS_OMP)
 #	pragma omp parallel for shared(                                                               \
 	  transA, transB, m, n, k, a, b, c, alpha, beta, lda, ldb, ldc) default(none) schedule(static)
 #endif
			for (int64_t i = 0; i < m; ++i) {
				for (int64_t j = 0; j < n; ++j) {
					C sum;
					if (beta == 0)
						sum = 0;
					else
						sum = c[i * ldc + j];

					for (int64_t l = 0; l < k; ++l) {
						sum += a[transA ? i + l * lda : l + i * lda] *
							   b[transB ? l + j * ldb : j + l * ldb];
					}
					c[i * ldc + j] = sum * alpha;
				}
			}
		} else {
			// CUDA implementation
		}

		/*

		 for (int i = 0; i < a.dim(); i++)
			for (int j = 0; j < a.dim(); j++) {
				int sum = 0;
				for (int k = 0; k < a.dim(); k++)
					sum += a(i,k) * b(k,j);
				c(i,j) = sum;
			}
		 }

		 */
	}

#if defined(LIBRAPID_HAS_BLAS)
	template<>
	float dot<device::CPU, float, float>(int64_t n, float *__restrict x, int64_t incX,
										 float *__restrict y, int64_t incY);

	template<>
	double dot<device::CPU, double, double>(int64_t n, double *__restrict x, int64_t incX,
											double *__restrict y, int64_t incY);

	template<>
	void gemm<device::CPU, float, float, float>(bool transA, bool transB, int64_t m, int64_t n,
												int64_t k, float alpha, const float *__restrict a,
												int64_t lda, const float *__restrict b, int64_t ldb,
												float beta, float *__restrict c, int64_t ldc);

	template<>
	void gemm<device::CPU, double, double, double>(bool transA, bool transB, int64_t m, int64_t n,
												   int64_t k, double alpha,
												   const double *__restrict a, int64_t lda,
												   const double *__restrict b, int64_t ldb,
												   double beta, double *__restrict c, int64_t ldc);
#endif

#if defined(LIBRAPID_HAS_CUDA)
	namespace impl {
		extended::float16_t dot(int64_t n, extended::float16_t *__restrict x, int64_t incX,
								extended::float16_t *__restrict y, int64_t incY,
								cublasHandle_t *handles = &(memory::cublasHandles[0]));

		float dot(int64_t n, float *__restrict x, int64_t incX, float *__restrict y, int64_t incY,
				  cublasHandle_t *handles = &(memory::cublasHandles[0]));

		double dot(int64_t n, double *__restrict x, int64_t incX, double *__restrict y,
				   int64_t incY, cublasHandle_t *handles = &(memory::cublasHandles[0]));
	} // namespace impl

	template<>
	LR_INLINE extended::float16_t dot<device::GPU, extended::float16_t, extended::float16_t>(
	  int64_t n, extended::float16_t *__restrict x, int64_t incX, extended::float16_t *__restrict y,
	  int64_t incY) {
		return impl::dot(n, x, incX, y, incY);
	}

	template<>
	LR_INLINE float dot<device::GPU, float, float>(int64_t n, float *__restrict x, int64_t incX,
												   float *__restrict y, int64_t incY) {
		return impl::dot(n, x, incX, y, incY);
	}

	template<>
	LR_INLINE double dot<device::GPU, double, double>(int64_t n, double *__restrict x, int64_t incX,
													  double *__restrict y, int64_t incY) {
		return impl::dot(n, x, incX, y, incY);
	}
#endif
} // namespace librapid::blas
