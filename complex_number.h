#include <iostream>
using namespace std;

class Complex {

public:
    Complex();
    Complex(double, double);
    ~Complex();

    Complex operator+(const Complex &) const;
    Complex operator-(const Complex &) const;
    Complex operator*(const Complex &) const;

    void operator=(const Complex &);

    bool operator!= (const Complex &) const;
    bool operator==(Complex &) const;

    friend istream & operator>>(istream &, Complex &);
    friend ostream & operator<<(ostream &, const Complex &);

private:
    double real;
    double imaginary;

};


