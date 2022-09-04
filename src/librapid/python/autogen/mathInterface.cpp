
#include <librapid/librapid.hpp>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>
#include <functional>
#include <string>

// Just remove these. They're pointless
#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

namespace lrc = librapid;
namespace py = pybind11;

void init_math(py::module &module) {
	module.def("abs", [](const int64_t & val) { return lrc::abs(val); }, py::arg("val"));
	module.def("floor", [](const int64_t & val) { return lrc::floor(val); }, py::arg("val"));
	module.def("ceil", [](const int64_t & val) { return lrc::ceil(val); }, py::arg("val"));
	module.def("pow", [](const int64_t & base, const int64_t & power) { return lrc::pow(base, power); }, py::arg("base"), py::arg("power"));
	module.def("sqrt", [](const int64_t & val) { return lrc::sqrt(val); }, py::arg("val"));
	module.def("exp", [](const int64_t & val) { return lrc::exp(val); }, py::arg("val"));
	module.def("exp2", [](const int64_t & val) { return lrc::exp2(val); }, py::arg("val"));
	module.def("exp10", [](const int64_t & val) { return lrc::exp10(val); }, py::arg("val"));
	module.def("log", [](const int64_t & val) { return lrc::log(val); }, py::arg("val"));
	module.def("log2", [](const int64_t & val) { return lrc::log2(val); }, py::arg("val"));
	module.def("log10", [](const int64_t & val) { return lrc::log10(val); }, py::arg("val"));
	module.def("sin", [](const int64_t & val) { return lrc::sin(val); }, py::arg("val"));
	module.def("cos", [](const int64_t & val) { return lrc::cos(val); }, py::arg("val"));
	module.def("tan", [](const int64_t & val) { return lrc::tan(val); }, py::arg("val"));
	module.def("asin", [](const int64_t & val) { return lrc::asin(val); }, py::arg("val"));
	module.def("acos", [](const int64_t & val) { return lrc::acos(val); }, py::arg("val"));
	module.def("atan", [](const int64_t & val) { return lrc::atan(val); }, py::arg("val"));
	module.def("atan2", [](const int64_t & a, const int64_t & b) { return lrc::atan2(a, b); }, py::arg("a"), py::arg("b"));
	module.def("csc", [](const int64_t & val) { return lrc::csc(val); }, py::arg("val"));
	module.def("sec", [](const int64_t & val) { return lrc::sec(val); }, py::arg("val"));
	module.def("cot", [](const int64_t & val) { return lrc::cot(val); }, py::arg("val"));
	module.def("acsc", [](const int64_t & val) { return lrc::acsc(val); }, py::arg("val"));
	module.def("asec", [](const int64_t & val) { return lrc::asec(val); }, py::arg("val"));
	module.def("acot", [](const int64_t & val) { return lrc::acot(val); }, py::arg("val"));
	module.def("sinh", [](const int64_t & val) { return lrc::sinh(val); }, py::arg("val"));
	module.def("cosh", [](const int64_t & val) { return lrc::cosh(val); }, py::arg("val"));
	module.def("tanh", [](const int64_t & val) { return lrc::tanh(val); }, py::arg("val"));
	module.def("asinh", [](const int64_t & val) { return lrc::asinh(val); }, py::arg("val"));
	module.def("acosh", [](const int64_t & val) { return lrc::acosh(val); }, py::arg("val"));
	module.def("atanh", [](const int64_t & val) { return lrc::atanh(val); }, py::arg("val"));
	module.def("mod", [](const int64_t & val, const int64_t & divisor) { return lrc::mod(val, divisor); }, py::arg("val"), py::arg("divisor"));
	module.def("round", [](const int64_t & val, int64_t dp) { return lrc::round(val, dp); }, py::arg("val"), py::arg("dp") = int64_t(0));
	module.def("roundSigFig", [](const int64_t & val, int64_t dp) { return lrc::roundSigFig(val, dp); }, py::arg("val"), py::arg("dp") = int64_t(3));
	module.def("roundTo", [](const int64_t & val, const int64_t & num) { return lrc::roundTo(val, num); }, py::arg("val"), py::arg("num"));
	module.def("roundUpTo", [](const int64_t & val, const int64_t & num) { return lrc::roundUpTo(val, num); }, py::arg("val"), py::arg("num"));
	module.def("clamp", [](const int64_t & x, const int64_t & lower, const int64_t & upper) { return librapid::clamp(x, lower, upper); }, py::arg("x"), py::arg("lower"), py::arg("upper"));
	module.def("smoothStep", [](const int64_t & edge0, const int64_t & edge1, const int64_t & x) { return librapid::smoothStep(edge0, edge1, x); }, py::arg("edge0"), py::arg("edge1"), py::arg("x"));
	module.def("abs", [](const double & val) { return lrc::abs(val); }, py::arg("val"));
	module.def("floor", [](const double & val) { return lrc::floor(val); }, py::arg("val"));
	module.def("ceil", [](const double & val) { return lrc::ceil(val); }, py::arg("val"));
	module.def("pow", [](const double & base, const double & power) { return lrc::pow(base, power); }, py::arg("base"), py::arg("power"));
	module.def("sqrt", [](const double & val) { return lrc::sqrt(val); }, py::arg("val"));
	module.def("exp", [](const double & val) { return lrc::exp(val); }, py::arg("val"));
	module.def("exp2", [](const double & val) { return lrc::exp2(val); }, py::arg("val"));
	module.def("exp10", [](const double & val) { return lrc::exp10(val); }, py::arg("val"));
	module.def("log", [](const double & val) { return lrc::log(val); }, py::arg("val"));
	module.def("log2", [](const double & val) { return lrc::log2(val); }, py::arg("val"));
	module.def("log10", [](const double & val) { return lrc::log10(val); }, py::arg("val"));
	module.def("sin", [](const double & val) { return lrc::sin(val); }, py::arg("val"));
	module.def("cos", [](const double & val) { return lrc::cos(val); }, py::arg("val"));
	module.def("tan", [](const double & val) { return lrc::tan(val); }, py::arg("val"));
	module.def("asin", [](const double & val) { return lrc::asin(val); }, py::arg("val"));
	module.def("acos", [](const double & val) { return lrc::acos(val); }, py::arg("val"));
	module.def("atan", [](const double & val) { return lrc::atan(val); }, py::arg("val"));
	module.def("atan2", [](const double & a, const double & b) { return lrc::atan2(a, b); }, py::arg("a"), py::arg("b"));
	module.def("csc", [](const double & val) { return lrc::csc(val); }, py::arg("val"));
	module.def("sec", [](const double & val) { return lrc::sec(val); }, py::arg("val"));
	module.def("cot", [](const double & val) { return lrc::cot(val); }, py::arg("val"));
	module.def("acsc", [](const double & val) { return lrc::acsc(val); }, py::arg("val"));
	module.def("asec", [](const double & val) { return lrc::asec(val); }, py::arg("val"));
	module.def("acot", [](const double & val) { return lrc::acot(val); }, py::arg("val"));
	module.def("sinh", [](const double & val) { return lrc::sinh(val); }, py::arg("val"));
	module.def("cosh", [](const double & val) { return lrc::cosh(val); }, py::arg("val"));
	module.def("tanh", [](const double & val) { return lrc::tanh(val); }, py::arg("val"));
	module.def("asinh", [](const double & val) { return lrc::asinh(val); }, py::arg("val"));
	module.def("acosh", [](const double & val) { return lrc::acosh(val); }, py::arg("val"));
	module.def("atanh", [](const double & val) { return lrc::atanh(val); }, py::arg("val"));
	module.def("mod", [](const double & val, const double & divisor) { return lrc::mod(val, divisor); }, py::arg("val"), py::arg("divisor"));
	module.def("round", [](const double & val, int64_t dp) { return lrc::round(val, dp); }, py::arg("val"), py::arg("dp") = int64_t(0));
	module.def("roundSigFig", [](const double & val, int64_t dp) { return lrc::roundSigFig(val, dp); }, py::arg("val"), py::arg("dp") = int64_t(3));
	module.def("roundTo", [](const double & val, const double & num) { return lrc::roundTo(val, num); }, py::arg("val"), py::arg("num"));
	module.def("roundUpTo", [](const double & val, const double & num) { return lrc::roundUpTo(val, num); }, py::arg("val"), py::arg("num"));
	module.def("clamp", [](const double & x, const double & lower, const double & upper) { return librapid::clamp(x, lower, upper); }, py::arg("x"), py::arg("lower"), py::arg("upper"));
	module.def("smoothStep", [](const double & edge0, const double & edge1, const double & x) { return librapid::smoothStep(edge0, edge1, x); }, py::arg("edge0"), py::arg("edge1"), py::arg("x"));
	module.def("abs", [](const librapid::mpfr & val) { return lrc::abs(val); }, py::arg("val"));
	module.def("floor", [](const librapid::mpfr & val) { return lrc::floor(val); }, py::arg("val"));
	module.def("ceil", [](const librapid::mpfr & val) { return lrc::ceil(val); }, py::arg("val"));
	module.def("pow", [](const librapid::mpfr & base, const librapid::mpfr & power) { return lrc::pow(base, power); }, py::arg("base"), py::arg("power"));
	module.def("sqrt", [](const librapid::mpfr & val) { return lrc::sqrt(val); }, py::arg("val"));
	module.def("exp", [](const librapid::mpfr & val) { return lrc::exp(val); }, py::arg("val"));
	module.def("exp2", [](const librapid::mpfr & val) { return lrc::exp2(val); }, py::arg("val"));
	module.def("exp10", [](const librapid::mpfr & val) { return lrc::exp10(val); }, py::arg("val"));
	module.def("log", [](const librapid::mpfr & val) { return lrc::log(val); }, py::arg("val"));
	module.def("log2", [](const librapid::mpfr & val) { return lrc::log2(val); }, py::arg("val"));
	module.def("log10", [](const librapid::mpfr & val) { return lrc::log10(val); }, py::arg("val"));
	module.def("sin", [](const librapid::mpfr & val) { return lrc::sin(val); }, py::arg("val"));
	module.def("cos", [](const librapid::mpfr & val) { return lrc::cos(val); }, py::arg("val"));
	module.def("tan", [](const librapid::mpfr & val) { return lrc::tan(val); }, py::arg("val"));
	module.def("asin", [](const librapid::mpfr & val) { return lrc::asin(val); }, py::arg("val"));
	module.def("acos", [](const librapid::mpfr & val) { return lrc::acos(val); }, py::arg("val"));
	module.def("atan", [](const librapid::mpfr & val) { return lrc::atan(val); }, py::arg("val"));
	module.def("atan2", [](const librapid::mpfr & a, const librapid::mpfr & b) { return lrc::atan2(a, b); }, py::arg("a"), py::arg("b"));
	module.def("csc", [](const librapid::mpfr & val) { return lrc::csc(val); }, py::arg("val"));
	module.def("sec", [](const librapid::mpfr & val) { return lrc::sec(val); }, py::arg("val"));
	module.def("cot", [](const librapid::mpfr & val) { return lrc::cot(val); }, py::arg("val"));
	module.def("acsc", [](const librapid::mpfr & val) { return lrc::acsc(val); }, py::arg("val"));
	module.def("asec", [](const librapid::mpfr & val) { return lrc::asec(val); }, py::arg("val"));
	module.def("acot", [](const librapid::mpfr & val) { return lrc::acot(val); }, py::arg("val"));
	module.def("sinh", [](const librapid::mpfr & val) { return lrc::sinh(val); }, py::arg("val"));
	module.def("cosh", [](const librapid::mpfr & val) { return lrc::cosh(val); }, py::arg("val"));
	module.def("tanh", [](const librapid::mpfr & val) { return lrc::tanh(val); }, py::arg("val"));
	module.def("asinh", [](const librapid::mpfr & val) { return lrc::asinh(val); }, py::arg("val"));
	module.def("acosh", [](const librapid::mpfr & val) { return lrc::acosh(val); }, py::arg("val"));
	module.def("atanh", [](const librapid::mpfr & val) { return lrc::atanh(val); }, py::arg("val"));
	module.def("mod", [](const librapid::mpfr & val, const librapid::mpfr & divisor) { return lrc::mod(val, divisor); }, py::arg("val"), py::arg("divisor"));
	module.def("round", [](const librapid::mpfr & val, int64_t dp) { return lrc::round(val, dp); }, py::arg("val"), py::arg("dp") = int64_t(0));
	module.def("roundSigFig", [](const librapid::mpfr & val, int64_t dp) { return lrc::roundSigFig(val, dp); }, py::arg("val"), py::arg("dp") = int64_t(3));
	module.def("roundTo", [](const librapid::mpfr & val, const librapid::mpfr & num) { return lrc::roundTo(val, num); }, py::arg("val"), py::arg("num"));
	module.def("roundUpTo", [](const librapid::mpfr & val, const librapid::mpfr & num) { return lrc::roundUpTo(val, num); }, py::arg("val"), py::arg("num"));
	module.def("clamp", [](const librapid::mpfr & x, const librapid::mpfr & lower, const librapid::mpfr & upper) { return librapid::clamp(x, lower, upper); }, py::arg("x"), py::arg("lower"), py::arg("upper"));
	module.def("smoothStep", [](const librapid::mpfr & edge0, const librapid::mpfr & edge1, const librapid::mpfr & x) { return librapid::smoothStep(edge0, edge1, x); }, py::arg("edge0"), py::arg("edge1"), py::arg("x"));
	module.def("abs", [](const librapid::Complex<float> & val) { return lrc::abs(val); }, py::arg("val"));
	module.def("floor", [](const librapid::Complex<float> & val) { return lrc::floor(val); }, py::arg("val"));
	module.def("ceil", [](const librapid::Complex<float> & val) { return lrc::ceil(val); }, py::arg("val"));
	module.def("pow", [](const librapid::Complex<float> & base, const librapid::Complex<float> & power) { return lrc::pow(base, power); }, py::arg("base"), py::arg("power"));
	module.def("sqrt", [](const librapid::Complex<float> & val) { return lrc::sqrt(val); }, py::arg("val"));
	module.def("exp", [](const librapid::Complex<float> & val) { return lrc::exp(val); }, py::arg("val"));
	module.def("exp2", [](const librapid::Complex<float> & val) { return lrc::exp2(val); }, py::arg("val"));
	module.def("exp10", [](const librapid::Complex<float> & val) { return lrc::exp10(val); }, py::arg("val"));
	module.def("log", [](const librapid::Complex<float> & val) { return lrc::log(val); }, py::arg("val"));
	module.def("log2", [](const librapid::Complex<float> & val) { return lrc::log2(val); }, py::arg("val"));
	module.def("log10", [](const librapid::Complex<float> & val) { return lrc::log10(val); }, py::arg("val"));
	module.def("sin", [](const librapid::Complex<float> & val) { return lrc::sin(val); }, py::arg("val"));
	module.def("cos", [](const librapid::Complex<float> & val) { return lrc::cos(val); }, py::arg("val"));
	module.def("tan", [](const librapid::Complex<float> & val) { return lrc::tan(val); }, py::arg("val"));
	module.def("asin", [](const librapid::Complex<float> & val) { return lrc::asin(val); }, py::arg("val"));
	module.def("acos", [](const librapid::Complex<float> & val) { return lrc::acos(val); }, py::arg("val"));
	module.def("atan", [](const librapid::Complex<float> & val) { return lrc::atan(val); }, py::arg("val"));
	module.def("atan2", [](const librapid::Complex<float> & a, const librapid::Complex<float> & b) { return lrc::atan2(a, b); }, py::arg("a"), py::arg("b"));
	module.def("csc", [](const librapid::Complex<float> & val) { return lrc::csc(val); }, py::arg("val"));
	module.def("sec", [](const librapid::Complex<float> & val) { return lrc::sec(val); }, py::arg("val"));
	module.def("cot", [](const librapid::Complex<float> & val) { return lrc::cot(val); }, py::arg("val"));
	module.def("acsc", [](const librapid::Complex<float> & val) { return lrc::acsc(val); }, py::arg("val"));
	module.def("asec", [](const librapid::Complex<float> & val) { return lrc::asec(val); }, py::arg("val"));
	module.def("acot", [](const librapid::Complex<float> & val) { return lrc::acot(val); }, py::arg("val"));
	module.def("sinh", [](const librapid::Complex<float> & val) { return lrc::sinh(val); }, py::arg("val"));
	module.def("cosh", [](const librapid::Complex<float> & val) { return lrc::cosh(val); }, py::arg("val"));
	module.def("tanh", [](const librapid::Complex<float> & val) { return lrc::tanh(val); }, py::arg("val"));
	module.def("asinh", [](const librapid::Complex<float> & val) { return lrc::asinh(val); }, py::arg("val"));
	module.def("acosh", [](const librapid::Complex<float> & val) { return lrc::acosh(val); }, py::arg("val"));
	module.def("atanh", [](const librapid::Complex<float> & val) { return lrc::atanh(val); }, py::arg("val"));
	module.def("mod", [](const librapid::Complex<float> & val, const librapid::Complex<float> & divisor) { return lrc::mod(val, divisor); }, py::arg("val"), py::arg("divisor"));
	module.def("round", [](const librapid::Complex<float> & val, int64_t dp) { return lrc::round(val, dp); }, py::arg("val"), py::arg("dp") = int64_t(0));
	module.def("roundSigFig", [](const librapid::Complex<float> & val, int64_t dp) { return lrc::roundSigFig(val, dp); }, py::arg("val"), py::arg("dp") = int64_t(3));
	module.def("roundTo", [](const librapid::Complex<float> & val, const librapid::Complex<float> & num) { return lrc::roundTo(val, num); }, py::arg("val"), py::arg("num"));
	module.def("roundUpTo", [](const librapid::Complex<float> & val, const librapid::Complex<float> & num) { return lrc::roundUpTo(val, num); }, py::arg("val"), py::arg("num"));
	module.def("clamp", [](const librapid::Complex<float> & x, const librapid::Complex<float> & lower, const librapid::Complex<float> & upper) { return librapid::clamp(x, lower, upper); }, py::arg("x"), py::arg("lower"), py::arg("upper"));
	module.def("smoothStep", [](const librapid::Complex<float> & edge0, const librapid::Complex<float> & edge1, const librapid::Complex<float> & x) { return librapid::smoothStep(edge0, edge1, x); }, py::arg("edge0"), py::arg("edge1"), py::arg("x"));
	module.def("abs", [](const librapid::Complex<double> & val) { return lrc::abs(val); }, py::arg("val"));
	module.def("floor", [](const librapid::Complex<double> & val) { return lrc::floor(val); }, py::arg("val"));
	module.def("ceil", [](const librapid::Complex<double> & val) { return lrc::ceil(val); }, py::arg("val"));
	module.def("pow", [](const librapid::Complex<double> & base, const librapid::Complex<double> & power) { return lrc::pow(base, power); }, py::arg("base"), py::arg("power"));
	module.def("sqrt", [](const librapid::Complex<double> & val) { return lrc::sqrt(val); }, py::arg("val"));
	module.def("exp", [](const librapid::Complex<double> & val) { return lrc::exp(val); }, py::arg("val"));
	module.def("exp2", [](const librapid::Complex<double> & val) { return lrc::exp2(val); }, py::arg("val"));
	module.def("exp10", [](const librapid::Complex<double> & val) { return lrc::exp10(val); }, py::arg("val"));
	module.def("log", [](const librapid::Complex<double> & val) { return lrc::log(val); }, py::arg("val"));
	module.def("log2", [](const librapid::Complex<double> & val) { return lrc::log2(val); }, py::arg("val"));
	module.def("log10", [](const librapid::Complex<double> & val) { return lrc::log10(val); }, py::arg("val"));
	module.def("sin", [](const librapid::Complex<double> & val) { return lrc::sin(val); }, py::arg("val"));
	module.def("cos", [](const librapid::Complex<double> & val) { return lrc::cos(val); }, py::arg("val"));
	module.def("tan", [](const librapid::Complex<double> & val) { return lrc::tan(val); }, py::arg("val"));
	module.def("asin", [](const librapid::Complex<double> & val) { return lrc::asin(val); }, py::arg("val"));
	module.def("acos", [](const librapid::Complex<double> & val) { return lrc::acos(val); }, py::arg("val"));
	module.def("atan", [](const librapid::Complex<double> & val) { return lrc::atan(val); }, py::arg("val"));
	module.def("atan2", [](const librapid::Complex<double> & a, const librapid::Complex<double> & b) { return lrc::atan2(a, b); }, py::arg("a"), py::arg("b"));
	module.def("csc", [](const librapid::Complex<double> & val) { return lrc::csc(val); }, py::arg("val"));
	module.def("sec", [](const librapid::Complex<double> & val) { return lrc::sec(val); }, py::arg("val"));
	module.def("cot", [](const librapid::Complex<double> & val) { return lrc::cot(val); }, py::arg("val"));
	module.def("acsc", [](const librapid::Complex<double> & val) { return lrc::acsc(val); }, py::arg("val"));
	module.def("asec", [](const librapid::Complex<double> & val) { return lrc::asec(val); }, py::arg("val"));
	module.def("acot", [](const librapid::Complex<double> & val) { return lrc::acot(val); }, py::arg("val"));
	module.def("sinh", [](const librapid::Complex<double> & val) { return lrc::sinh(val); }, py::arg("val"));
	module.def("cosh", [](const librapid::Complex<double> & val) { return lrc::cosh(val); }, py::arg("val"));
	module.def("tanh", [](const librapid::Complex<double> & val) { return lrc::tanh(val); }, py::arg("val"));
	module.def("asinh", [](const librapid::Complex<double> & val) { return lrc::asinh(val); }, py::arg("val"));
	module.def("acosh", [](const librapid::Complex<double> & val) { return lrc::acosh(val); }, py::arg("val"));
	module.def("atanh", [](const librapid::Complex<double> & val) { return lrc::atanh(val); }, py::arg("val"));
	module.def("mod", [](const librapid::Complex<double> & val, const librapid::Complex<double> & divisor) { return lrc::mod(val, divisor); }, py::arg("val"), py::arg("divisor"));
	module.def("round", [](const librapid::Complex<double> & val, int64_t dp) { return lrc::round(val, dp); }, py::arg("val"), py::arg("dp") = int64_t(0));
	module.def("roundSigFig", [](const librapid::Complex<double> & val, int64_t dp) { return lrc::roundSigFig(val, dp); }, py::arg("val"), py::arg("dp") = int64_t(3));
	module.def("roundTo", [](const librapid::Complex<double> & val, const librapid::Complex<double> & num) { return lrc::roundTo(val, num); }, py::arg("val"), py::arg("num"));
	module.def("roundUpTo", [](const librapid::Complex<double> & val, const librapid::Complex<double> & num) { return lrc::roundUpTo(val, num); }, py::arg("val"), py::arg("num"));
	module.def("clamp", [](const librapid::Complex<double> & x, const librapid::Complex<double> & lower, const librapid::Complex<double> & upper) { return librapid::clamp(x, lower, upper); }, py::arg("x"), py::arg("lower"), py::arg("upper"));
	module.def("smoothStep", [](const librapid::Complex<double> & edge0, const librapid::Complex<double> & edge1, const librapid::Complex<double> & x) { return librapid::smoothStep(edge0, edge1, x); }, py::arg("edge0"), py::arg("edge1"), py::arg("x"));
	module.def("abs", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::abs(val); }, py::arg("val"));
	module.def("floor", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::floor(val); }, py::arg("val"));
	module.def("ceil", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::ceil(val); }, py::arg("val"));
	module.def("pow", [](const librapid::Complex<librapid::mpfr> & base, const librapid::Complex<librapid::mpfr> & power) { return lrc::pow(base, power); }, py::arg("base"), py::arg("power"));
	module.def("sqrt", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::sqrt(val); }, py::arg("val"));
	module.def("exp", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::exp(val); }, py::arg("val"));
	module.def("exp2", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::exp2(val); }, py::arg("val"));
	module.def("exp10", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::exp10(val); }, py::arg("val"));
	module.def("log", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::log(val); }, py::arg("val"));
	module.def("log2", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::log2(val); }, py::arg("val"));
	module.def("log10", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::log10(val); }, py::arg("val"));
	module.def("sin", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::sin(val); }, py::arg("val"));
	module.def("cos", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::cos(val); }, py::arg("val"));
	module.def("tan", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::tan(val); }, py::arg("val"));
	module.def("asin", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::asin(val); }, py::arg("val"));
	module.def("acos", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::acos(val); }, py::arg("val"));
	module.def("atan", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::atan(val); }, py::arg("val"));
	module.def("atan2", [](const librapid::Complex<librapid::mpfr> & a, const librapid::Complex<librapid::mpfr> & b) { return lrc::atan2(a, b); }, py::arg("a"), py::arg("b"));
	module.def("csc", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::csc(val); }, py::arg("val"));
	module.def("sec", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::sec(val); }, py::arg("val"));
	module.def("cot", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::cot(val); }, py::arg("val"));
	module.def("acsc", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::acsc(val); }, py::arg("val"));
	module.def("asec", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::asec(val); }, py::arg("val"));
	module.def("acot", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::acot(val); }, py::arg("val"));
	module.def("sinh", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::sinh(val); }, py::arg("val"));
	module.def("cosh", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::cosh(val); }, py::arg("val"));
	module.def("tanh", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::tanh(val); }, py::arg("val"));
	module.def("asinh", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::asinh(val); }, py::arg("val"));
	module.def("acosh", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::acosh(val); }, py::arg("val"));
	module.def("atanh", [](const librapid::Complex<librapid::mpfr> & val) { return lrc::atanh(val); }, py::arg("val"));
	module.def("mod", [](const librapid::Complex<librapid::mpfr> & val, const librapid::Complex<librapid::mpfr> & divisor) { return lrc::mod(val, divisor); }, py::arg("val"), py::arg("divisor"));
	module.def("round", [](const librapid::Complex<librapid::mpfr> & val, int64_t dp) { return lrc::round(val, dp); }, py::arg("val"), py::arg("dp") = int64_t(0));
	module.def("roundSigFig", [](const librapid::Complex<librapid::mpfr> & val, int64_t dp) { return lrc::roundSigFig(val, dp); }, py::arg("val"), py::arg("dp") = int64_t(3));
	module.def("roundTo", [](const librapid::Complex<librapid::mpfr> & val, const librapid::Complex<librapid::mpfr> & num) { return lrc::roundTo(val, num); }, py::arg("val"), py::arg("num"));
	module.def("roundUpTo", [](const librapid::Complex<librapid::mpfr> & val, const librapid::Complex<librapid::mpfr> & num) { return lrc::roundUpTo(val, num); }, py::arg("val"), py::arg("num"));
	module.def("clamp", [](const librapid::Complex<librapid::mpfr> & x, const librapid::Complex<librapid::mpfr> & lower, const librapid::Complex<librapid::mpfr> & upper) { return librapid::clamp(x, lower, upper); }, py::arg("x"), py::arg("lower"), py::arg("upper"));
	module.def("smoothStep", [](const librapid::Complex<librapid::mpfr> & edge0, const librapid::Complex<librapid::mpfr> & edge1, const librapid::Complex<librapid::mpfr> & x) { return librapid::smoothStep(edge0, edge1, x); }, py::arg("edge0"), py::arg("edge1"), py::arg("x"));
	module.def("map", [](double val, double start1, double stop1, double start2, double stop2) { return lrc::map(val, start1, stop1, start2, stop2); }, py::arg("val"), py::arg("start1"), py::arg("stop1"), py::arg("start2"), py::arg("stop2"));
	module.def("random", [](double lower, double upper, int64_t seed) { return librapid::random(lower, upper, seed); }, py::arg("lower") = double(0), py::arg("upper") = double(1), py::arg("seed") = int64_t(-1));
	module.def("randint", [](int64_t lower, int64_t upper, int64_t seed) { return librapid::randint(lower, upper, seed); }, py::arg("lower") = int64_t(0), py::arg("upper") = int64_t(0), py::arg("seed") = int64_t(-1));
	module.def("trueRandomEntropy", []() { return librapid::trueRandomEntropy(); });
	module.def("trueRandom", [](double lower, double upper) { return librapid::trueRandom(lower, upper); }, py::arg("lower") = double(0), py::arg("upper") = double(1));
	module.def("trueRandint", [](int64_t lower, int64_t upper) { return librapid::trueRandint(lower, upper); }, py::arg("lower") = int64_t(0), py::arg("upper") = int64_t(1));
	module.def("randomGaussian", []() { return librapid::randomGaussian(); });
	module.def("pow10", [](int64_t exponent) { return librapid::pow10(exponent); }, py::arg("exponent"));
	module.def("lerp", [](double a, double b, double t) { return librapid::lerp(a, b, t); }, py::arg("a"), py::arg("b"), py::arg("t"));

}