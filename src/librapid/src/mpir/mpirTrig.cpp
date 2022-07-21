#include <librapid/math/mpir.hpp>

namespace librapid {
	// Trigonometric Functionality for mpf

	mpf sin(const mpf &val) {
		// x = x % (2 * pi).
		// auto val = val_;
		// if (abs(val) > 6.28) {
		// 	val = fmod()
		// }

		// Get the current precision and increase it by five -- this ensures correct answers :)
		auto prec = val.get_prec() + 5;

		static mpf twoPi;
		static int64_t piPrec = 0;

		if (prec > piPrec) {
			fmt::print("Doing something\n");
			// twoPi  = pi((int64_t)((double)piPrec / log2(10))) * 2;
			Chudnovsky chud((int64_t)((double)piPrec / log2(10)) + 1);
			twoPi = chud.pi() * 2;
			piPrec = (int64_t)prec;
		}

		if (abs(val) >= twoPi) return sin(fmod(val, twoPi));

		mpf i, lastS, s, fact, num, sign;
		mpf_init2(lastS.get_mpf_t(), prec);
		mpf_init2(s.get_mpf_t(), prec);
		mpf_init2(fact.get_mpf_t(), prec);
		mpf_init2(num.get_mpf_t(), prec);
		mpf_init2(sign.get_mpf_t(), prec);
		i	  = 1;
		lastS = 0;
		s	  = val;
		fact  = 1;
		num	  = val;
		sign  = 1;

		while (s != lastS) {
			lastS = s;
			i += 2;
			fact *= i * (i - 1);
			num *= val * val;
			sign *= -1;
			s += num / fact * sign;
		}
		s.set_prec(prec - 5);
		return s;
	}
} // namespace librapid