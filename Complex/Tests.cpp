#define CATCH_CONFIG_MAIN

#include "../Catch/Catch.hpp"
#include "Complex.hpp"
#include <complex>

// Operator testing
TEST_CASE("operator - addition")
{
	Complex c1(2.0, 5.0), c2(3.0, 4.0), r;
	r = c1 + c2;

	REQUIRE(r.real() == 5);
	REQUIRE(r.imag() == 9);

	// Assertions using std::complex
	std::complex<double> co1(2.0, 5.0), co2(3.0, 4.0), re;
	re = co1 + co2;

	REQUIRE(re.real() == 5);
	REQUIRE(re.imag() == 9);
}

TEST_CASE("operator - subtraction")
{
	Complex c1(2.0, 5.0), c2(3.0, 4.0), r;
	r = c1 - c2;

	// Assertions using std::complex
	std::complex<double> co1(2.0, 5.0), co2(3.0, 4.0), re;
	re = co1 - co2;

	REQUIRE(r.real() == re.real());
	REQUIRE(r.imag() == re.imag());
}

TEST_CASE("operator - multiplication")
{
	Complex c1(2.0, 5.0), c2(3.0, 4.0), r;
	r = c1 * c2;

	// Assertions using std::complex
	std::complex<double> co1(2.0, 5.0), co2(3.0, 4.0), re;
	re = co1 * co2;

	REQUIRE(r.real() == re.real());
	REQUIRE(r.imag() == re.imag());
}

TEST_CASE("operator - division")
{
	Complex c1(2.0, 5.0), c2(3.0, 4.0), r;
	r = c1 / c2;

	// Assertions using std::complex
	std::complex<double> co1(2.0, 5.0), co2(3.0, 4.0), re;
	re = co1 / co2;

	REQUIRE(r.real() == re.real());
	REQUIRE(r.imag() == re.imag());
}

TEST_CASE("operator - equality")
{
	Complex c1(2.0, 5.0), c2(2.0, 5.0);

	// Assertions using std::complex
	std::complex<double> co1(2.0, 5.0), co2(2.0, 5.0);

	REQUIRE(c1 == c2);
	REQUIRE(co1 == co2);
}

TEST_CASE("operator - inequality")
{
	Complex c1(2.0, 5.0), c2(2.0, 3.0);

	// Assertions using std::complex
	std::complex<double> co1(2.0, 5.0), co2(2.0, 3.0);

	REQUIRE(c1 != c2);
	REQUIRE(co1 != co2);
}

// Conjucation and magnitude testing
TEST_CASE("conjucation")
{
	Complex c1(2.0, 5.0), r;
	r = c1.conj();

	// Assertions using std::complex
	std::complex<double> co1(2.0, 5.0), re;
	re = std::conj(co1);

	REQUIRE(r.real() == re.real());
	REQUIRE(r.imag() == re.imag());
}

TEST_CASE("magnitude")
{
	Complex c1(2.0, 5.0), c2(3.0, 4.0);

	// Assertions using std::complex
	std::complex<double> co1(2.0, 5.0), co2(3.0, 4.0);

	REQUIRE(c1.abs() == std::abs(co1));
	REQUIRE(c2.abs() == std::abs(co2));
}

// Raise to power testing
TEST_CASE("raise to power")
{
	Complex c1(2.0, 5.0), r;
	r = pow_c(c1, 2);

	// Assertions using std::complex
	std::complex<double> co1(2.0, 5.0), re;
	re = std::pow(co1, 2);

	REQUIRE(r.real() == re.real());
	REQUIRE(r.imag() == re.imag());
}