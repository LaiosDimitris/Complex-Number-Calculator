#include <iostream>

class Complex
{
public:
    Complex();
    Complex(double re);
    Complex(double re, double im);

    Complex(const Complex& other);

    double real() const;
    double imag() const;

    Complex conj() const;
    double abs() const;

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Complex& c);

private:
    double re;
    double im;
};

Complex pow_c(const Complex& c, int exp);