#ifndef LIBRAPID_CORE_GLOBAL_HPP
#define LIBRAPID_CORE_GLOBAL_HPP

/*
 * Global variables required for LibRapid, such as version number, number of threads,
 * CUDA-related configuration, etc.
 */

namespace librapid::global {
	// Should ASSERT functions error or throw exceptions?
	extern bool throwOnAssert;

	/// Arrays with more elements than this will run with multithreaded implementations
	extern size_t multithreadThreshold;

	// Number of columns required for a matrix to be parallelized in GEMM
	extern size_t gemmMultithreadThreshold;

	// Number of threads used by LibRapid
	extern size_t numThreads;

	// Size of a cache line in bytes
	extern size_t cacheLineSize;

	// Memory alignment for LibRapid
	extern size_t memoryAlignment;

#if defined(LIBRAPID_HAS_OPENCL)
	// OpenCL device list
	extern std::vector<cl::Device> openclDevices;

	// OpenCL context
	extern cl::Context openCLContext;

	// OpenCL device
	extern cl::Device openCLDevice;

	// OpenCL command queue
	extern cl::CommandQueue openCLQueue;

	// OpenCL program sources
	extern cl::Program::Sources openCLSources;

	// OpenCL program
	extern cl::Program openCLProgram;

	// True if OpenCL has been configured
	extern bool openCLConfigured;
#endif // LIBRAPID_HAS_OPENCL

#if defined(LIBRAPID_HAS_CUDA)
	// LibRapid's CUDA stream -- this removes the need for calling cudaDeviceSynchronize()
	extern cudaStream_t cudaStream;
	extern cublasHandle_t cublasHandle;
	extern jitify::JitCache jitCache;
#endif // LIBRAPID_HAS_CUDA
} // namespace librapid::global

#endif // LIBRAPID_CORE_GLOBAL_HPP