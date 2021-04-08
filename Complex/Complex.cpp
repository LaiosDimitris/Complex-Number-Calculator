#include <cmath>
#include "Complex.hpp"

// Constructors
Complex::Complex()
{
    this->re = 0.0;
    this->im = 0.0;
}

Complex::Complex(double re)
{
    this->re = re;
    this->im = 0.0;
}

Complex::Complex(double re, double im)
{
    this->re = re;
    this->im = im;
}

// Copy Constructor
Complex::Complex(const Complex& other)
{
    this->re = other.re;
    this->im = other.im;
}

// Getters
double Complex::real() const { return this->re; }
double Complex::imag() const { return this->im; }

// Conjucate and Magnitude functions
Complex Complex::conj() const
{
    return Complex(this->re, this->im * (-1));
}

double Complex::abs() const
{
    return sqrt(pow(this->re, 2) + pow(this->im, 2));
}

// Operator overloading
Complex Complex::operator+(const Complex& other) const
{
    return Complex(this->re + other.re, this->im + other.im);
}

Complex Complex::operator-(const Complex& other) const
{
    return Complex(this->re - other.re, this->im - other.im);
}

Complex Complex::operator*(const Complex& other) const
{
    return Complex(
        (this->re * other.re) - (this->im * other.im),
        (this->re * other.im) + (this->im * other.re)
    );
}

Complex Complex::operator/(const Complex& other) const
{
    return Complex(
        ((this->re * other.re) + (this->im * other.im)) / (pow(other.re, 2) + pow(other.im, 2)),
        ((this->im * other.re) - (this->re * other.im)) / (pow(other.re, 2) + pow(other.im, 2))
    );
}

bool Complex::operator==(const Complex& other) const
{
    if (this->re == other.re && this->im == other.im) {
        return true;
    }
    else {
        return false;
    }
}

bool Complex::operator!=(const Complex& other) const
{
    if (this->re != other.re || this->im != other.im) {
        return true;
    }
    else {
        return false;
    }
}

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
    if (c.im == 0) {
        os << c.re;
    }
    else if (c.im < 0) {
        os << c.re << " - " << -c.im << "i";
    }
    else {
        os << c.re << " + " << c.im << "i";
    }

    return os;
}

// Raise to power function
Complex pow_c(const Complex& c, int exp)
{
    Complex result = c;

    for (int i = 1; i < exp; i++)
    {
        result = result * c;
    }

    return result;
}