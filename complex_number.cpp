//Complex.cpp

#include <iostream>
#include "complex_number.h"

using namespace std;

Complex::Complex(): real(0)
                  , imaginary(0) { }


Complex::Complex(double real, double imaginary): real(real)
                                               , imaginary(imaginary) { }


Complex::~Complex() { }


Complex Complex::operator+(const Complex & right) const {

    Complex sum(this->real + right.real,
                this->imaginary + right.imaginary);

    return sum;
}

Complex Complex::operator-(const Complex & right) const {

    return Complex (this->real - right.real,
                    this->imaginary - right.imaginary);
}

Complex Complex::operator*(const Complex & right) const {

    double realPart = this->real * right.real - this->imaginary * right.imaginary;
    double imgPart = this->real * right.imaginary + this->imaginary * right.imaginary;

    return Complex(realPart, imgPart);
}

bool Complex::operator!=(const Complex &right) const {

    if (this->real == right.real &&
        this->imaginary == right.imaginary)
        return false;
    else
        return true;
}

bool Complex::operator== (Complex & right) const {

    if (this->real == right.real  &&
        this->imaginary == right.imaginary)
        return true;
    else
        return false;
}


void Complex::operator=(const Complex & right) {

    this->real = right.real;
    this->imaginary = right.imaginary;
}


istream& operator>>(istream & input, Complex & cNumber) {

    double real, imaginary;

    input>>real;

    input.ignore(256,',');

    input>>imaginary;

    input.ignore(256,'i');

    if (input.good()) {
        cNumber.real = real;
        cNumber.imaginary = imaginary;
    }

    return input;
}

ostream& operator<<(ostream & output, const Complex & cNumber) {

    output << "(" << cNumber.real<<", "<<cNumber.imaginary<<"i)";

    return output;
}