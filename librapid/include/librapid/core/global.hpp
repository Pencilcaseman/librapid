#ifndef LIBRAPID_CORE_GLOBAL_HPP
#define LIBRAPID_CORE_GLOBAL_HPP

/*
 * Global variables required for LibRapid, such as version number, number of threads,
 * CUDA-related configuration, etc.
 */

namespace librapid::global {
	// Should ASSERT functions error or throw exceptions?
	extern bool throwOnAssert;

	// Number of columns required for a matrix to be parallelized in GEMM
	extern int64_t gemmMultithreadThreshold;

	// Number of threads used by LibRapid
	extern int64_t numThreads;
}

#endif // LIBRAPID_CORE_GLOBAL_HPP