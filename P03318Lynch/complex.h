// complex.h
//
// CS318 P03 Complex Numbers
// Function prototypes for complex number class
// Written: Jeremy Lynch
// Date: 10/23/2023

#pragma once

class complex
{
	public:
		complex();

		complex(double a);

		complex(double a, double b);

		complex(const complex& c);

		complex& operator=(const complex& rhs);
		
		complex& operator+=(const complex& z);

		complex& operator-=(const complex& z);

		complex& operator*=(const complex& z);

		complex& operator/=(const complex& z);

		complex& operator+=(const double z);

		complex& operator-=(const double z);

		complex& operator*=(const double z);

		complex& operator/=(const double z);

		double real() const;

		double imag() const;
	
		double magnitude() const;

	private:
		double re, im;


};

complex operator+(const complex& z1, const complex& z2);

complex operator+(const complex& z1, const double x);

complex operator+(const double x, const complex& z);

complex operator-(const complex& z1, const complex& z2);

complex operator-(const complex& z1, const double x);

complex operator-(const double x, const complex& z);

complex operator*(const complex& z1, const complex& z2);

complex operator*(const complex& z1, const double x);

complex operator*(const double x, const complex& z);

complex operator/(const complex& z1, const complex& z2);

complex operator/(const complex& z1, const double x);

complex operator/(const double x, const complex& z);

complex operator+(const complex& z);

complex operator-(const complex& z);

bool operator==(const complex& z1, const complex& z2);

bool operator!=(const complex& z1, complex& z2);

std::istream& operator>>(std::istream& in, complex&);

std::ostream& operator<<(std::ostream& os, const complex&);

double magnitude(const complex& z); // also known as absolute value

double real(const complex& z);

double imag(const complex& z);

complex polar(const double r, const double theta); // Constructs a complex via polar coords.

complex polar(const double r);

complex conj(const complex& z); // Returns the conjugate of complex number

double norm(const complex& z); // Returns squared magnitude (absolute) value of z

double arg(const complex& z); // Returns arg (theta) value of complex number, z.


