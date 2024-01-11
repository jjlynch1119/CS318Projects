// complex.cpp
//
// CS318 P03 Complex Numbers
// Implementation of functions from complex.h
// Written: Jeremy Lynch
// Date: 10/23/2023

#include <iostream>
#include <cmath>
#include "complex.h"

complex::complex()
{
	re = 0.0;
	im = 0.0;
}

complex::complex(double a)
{
	re = a;
	im = 0.0;
}

complex::complex(double a, double b)
{
	re = a;
	im = b;
}

complex::complex(const complex& c)
{
	re = c.real();
	im = c.imag();
}

complex& complex::operator=(const complex & rhs)
{
	re = rhs.real();
	im = rhs.imag();

	return *this;
}

complex& complex::operator+=(const complex& z)
{
	re += z.real();
	im += z.imag();

	return *this;
}

complex& complex::operator-=(const complex& z)
{
	re -= z.real();
	im -= z.imag();

	return *this;
}

complex& complex::operator*=(const complex& z)
{
	double tempRe = re;
	double tempIm = im;

	re = (tempRe * z.real() - tempIm * z.imag());
	im = (tempRe * z.imag() + tempIm * z.real());

	return *this;
}

complex& complex::operator/=(const complex& z)
{
	double tempRe = re;
	double tempIm = im;

	re = (tempRe * z.real() + tempIm * z.imag()) / (z.real() * z.real() + z.imag() * z.imag());
	im = (tempIm * z.real() - tempRe * z.imag()) / (z.real() * z.real() + z.imag() * z.imag());

	return *this;
}

complex& complex::operator+=(const double z)
{
	re += z;

	return *this;
}

complex& complex::operator-=(const double z)
{
	re -= z;

	return *this;
}

complex& complex::operator*=(const double z)
{
	re = (re * z);
	im = (im * z);

	return *this;
}

complex& complex::operator/=(const double z)
{
	re = (re * z) / (z * z);
	im = (im * z) / (z * z);

	return *this;
}

double complex::real() const
{
	return re;
}

double complex::imag() const
{
	return im;
}

double complex::magnitude() const
{
	return sqrt(re * re + im * im);
}

complex operator+(const complex& z1, const complex& z2)
{
	complex c = z1;

	return c += z2;
}

complex operator+(const complex& z1, const double x)
{
	complex c = z1;

	return c += x;
}

complex operator+(const double x, const complex& z)
{
	complex c = z;

	return c += x;
}

complex operator-(const complex& z1, const complex& z2)
{
	complex c = z1;

	return c -= z2;
}

complex operator-(const complex& z1, const double x)
{
	complex c = z1;

	return c -= x;
}

complex operator-(const double x, const complex& z)
{
	complex c = z;

	return c -= x;
}

complex operator*(const complex& z1, const complex& z2)
{
	complex c = z1;

	c *= z2;

	return c;
}

complex operator*(const complex& z1, const double x)
{
	complex c = z1;

	return c *= x;
}

complex operator*(const double x, const complex& z)
{
	complex c = z;

	return c *= x;
}

complex operator/(const complex& z1, const complex& z2)
{
	complex c = z1;

	return c /= z2;
}

complex operator/(const complex& z1, const double x)
{
	complex c = z1;

	return c /= x;
}

complex operator/(const double x, const complex& z)
{
	complex c = z;

	return c /= x;
}

complex operator+(const complex& z)
{
	return complex(z);
}

complex operator-(const complex& z)
{
	return complex(-z.real(), -z.imag());
}

bool operator==(const complex & z1, const complex & z2)
{
	return z1.real() == z2.real() && z1.imag() == z2.imag();
}

bool operator!=(const complex& z1, complex& z2)
{
	return z1.real() != z2.real() || z1.imag() != z2.imag();
}

std::istream& operator>>(std::istream& is, complex& c)
{
	double re, im; 
	char discard;
	
	is >> discard;
	is >> re;
	is >> discard;
	is >> im;
	is >> discard;

	complex temp(re, im);

	c = temp;

	return is;
}

std::ostream& operator<<(std::ostream& os, const complex& c)
{
	os << "(" << c.real() << ", " << c.imag() << ")";

	return os;
}

double magnitude(const complex& z) // also known as absolute value
{
	return sqrt(z.real() * z.real() + z.imag() * z.imag());
}

double real(const complex& z)
{
	return z.real();
}

double imag(const complex& z)
{
	return z.imag();
}

complex polar(const double r, const double theta) // Constructs a complex via polar coords.
{	
	return complex(r * cos(theta), r * sin(theta));
}

complex polar(const double r)
{
	return complex(r * cos(0), r * sin(0));
}

complex conj(const complex& z) // Returns the conjugate of complex number
{
	complex c(z.real(), -z.imag());

	return c;
}

double norm(const complex& z) // Returns squared magnitude (absolute) value of z
{
	return abs(magnitude(z) * magnitude(z));
}

double arg(const complex& z) // Returns arg (theta) value of complex number, z.
{
	return atan2(z.imag(), z.real());
}

