//
// Created by victor on 24.01.2020.
//

#include "complex_number.h"
#include <vector>
using namespace std;

#ifndef UNTITLED_MATRIX_H
#define UNTITLED_MATRIX_H

class Matrix {


public:
    Matrix(std::vector<std::vector<Complex>>);
    ~Matrix() { }

    Matrix operator+(const Matrix &) const;
    Matrix operator*(const Matrix &) const;
    Matrix operator!();

    bool operator!= (const Matrix &);
    bool operator== (const Matrix &);


    friend ostream &operator<<(ostream &, const Matrix &);


private:
    vector<vector<Complex>> data;
};

#endif //UNTITLED_MATRIX_H
