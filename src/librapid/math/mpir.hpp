#pragma once

#include "../internal/config.hpp"

// MPIR (modified) for BigNumber types
#include <mpirxx.h>

namespace librapid {
	using mpz = mpz_class;
	using mpf = mpf_class;
	using mpq = mpq_class;

	namespace internal {
		static int64_t mpirPrec		 = 10;
		static int64_t mpirPrintPrec = 10;
	} // namespace internal

	inline void setMpirPrec(int64_t dig10) {
		internal::mpirPrec = dig10;
		mpf_set_default_prec((int64_t)((double)dig10 * 3.33));
	}

	inline void setMpirPrintPrec(int64_t dig10) { internal::mpirPrintPrec = dig10; }

	// Helper functions
	// mpf pi();

	namespace detail {
		struct PQT {
			mpz_class P, Q, T;
		};
	} // namespace detail

	class Chudnovsky {
	public:
		Chudnovsky(int64_t dig10 = 100);
		detail::PQT compPQT(int64_t n1, int64_t n2) const;
		mpf pi() const;

	private:
		mpz A, B, C, D, E, C3_24;
		int64_t DIGITS, PREC, N;
		double DIGITS_PER_TERM;
	};

	// void bs(const int64_t a, const int64_t b, mpz_class &Pab, mpz_class &Qab, mpz_class &Tab);
	// mpz_class chudnovsky(int64_t digits);

	mpf epsilon(const mpf &val = mpf_class());
	mpf fmod(const mpf &val, const mpf &mod);

	// Trigonometric Functionality for mpf
	mpf sin(const mpf &val);
	mpf cos(const mpf &val);
	mpf tan(const mpf &val);

} // namespace librapid

// Provide {fmt} printing capabilities
#ifdef FMT_API
template<>
struct fmt::formatter<mpz_class> {
	detail::dynamic_format_specs<char> specs_;

	template<typename ParseContext>
	constexpr auto parse(ParseContext &ctx) {
		auto begin = ctx.begin(), end = ctx.end();
		if (begin == end) return begin;
		using handler_type = detail::dynamic_specs_handler<ParseContext>;
		auto type		   = detail::type_constant<mpz_class, char>::value;
		auto checker	   = detail::specs_checker<handler_type>(handler_type(specs_, ctx), type);
		auto it			   = detail::parse_format_specs(begin, end, checker);
		auto eh			   = ctx.error_handler();
		detail::parse_float_type_spec(specs_, eh);
		return it;
	}

	template<typename FormatContext>
	inline auto format(const mpz_class &num, FormatContext &ctx) {
		try {
			std::stringstream ss;
			ss << std::fixed;
			ss.precision(specs_.precision < 1 ? 10 : specs_.precision);
			ss << num;
			return fmt::format_to(ctx.out(), ss.str());
		} catch (std::exception &e) {
			LR_ASSERT("Invalid Format Specifier: {}", e.what());
			return fmt::format_to(ctx.out(), "FORMAT ERROR");
		}
	}
};

template<>
struct fmt::formatter<mpf_class> {
	detail::dynamic_format_specs<char> specs_;

	template<typename ParseContext>
	constexpr auto parse(ParseContext &ctx) {
		auto begin = ctx.begin(), end = ctx.end();
		if (begin == end) return begin;
		using handler_type = detail::dynamic_specs_handler<ParseContext>;
		auto type		   = detail::type_constant<mpf_class, char>::value;
		auto checker	   = detail::specs_checker<handler_type>(handler_type(specs_, ctx), type);
		auto it			   = detail::parse_format_specs(begin, end, checker);
		auto eh			   = ctx.error_handler();
		detail::parse_float_type_spec(specs_, eh);
		return it;
	}

	template<typename FormatContext>
	inline auto format(const mpf_class &num, FormatContext &ctx) {
		try {
			std::stringstream ss;
			ss << std::fixed;
			ss.precision(specs_.precision < 1 ? 10 : specs_.precision);
			ss << num;
			return fmt::format_to(ctx.out(), ss.str());
		} catch (std::exception &e) {
			LR_ASSERT("Invalid Format Specifier: {}", e.what());
			return fmt::format_to(ctx.out(), "FORMAT ERROR");
		}
	}
};

template<>
struct fmt::formatter<mpq_class> {
	detail::dynamic_format_specs<char> specs_;

	template<typename ParseContext>
	constexpr auto parse(ParseContext &ctx) {
		auto begin = ctx.begin(), end = ctx.end();
		if (begin == end) return begin;
		using handler_type = detail::dynamic_specs_handler<ParseContext>;
		auto type		   = detail::type_constant<mpq_class, char>::value;
		auto checker	   = detail::specs_checker<handler_type>(handler_type(specs_, ctx), type);
		auto it			   = detail::parse_format_specs(begin, end, checker);
		auto eh			   = ctx.error_handler();
		detail::parse_float_type_spec(specs_, eh);
		return it;
	}

	template<typename FormatContext>
	inline auto format(const mpq_class &num, FormatContext &ctx) {
		try {
			std::stringstream ss;
			ss << std::fixed;
			ss.precision(specs_.precision < 1 ? 10 : specs_.precision);
			ss << num;
			return fmt::format_to(ctx.out(), ss.str());
		} catch (std::exception &e) {
			LR_ASSERT("Invalid Format Specifier: {}", e.what());
			return fmt::format_to(ctx.out(), "FORMAT ERROR");
		}
	}
};
#endif // FMT_API
