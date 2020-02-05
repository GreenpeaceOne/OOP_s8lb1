//
// Created by victor on 24.01.2020.
//

#include "Matrix.h"

Matrix::Matrix(std::vector<std::vector<Complex>> getData): data(getData) {};

Matrix Matrix::operator+(const Matrix &right) const {

    Matrix result(*this);

    for (int i = 0; i < this->data.size(); i++) {
        for (int j = 0; j < this->data[i].size(); j++) {

            result.data[i][j] = result.data[i][j] + right.data[i][j];
        }
    }

    return result;
}


Matrix Matrix::operator*(const Matrix &right) const {

    auto result(*this);
    int size = right.data.size();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result.data[i][j] = Complex(0, 0);
            for (int k = 0; k < size; k++)
                result.data[i][j] = result.data[i][j] + this->data[i][k] * right.data[k][j];
        }
    }

    return result;
}

Matrix Matrix::operator!() {

    Matrix result(*this);

    int col = this->data.size();
    int row = this->data[0].size();

    Matrix tmp(*this);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result.data[i][j] = this->data[j][i];
        }
    }


    return result;
}

bool Matrix::operator!=(const Matrix &right) {
    bool parity = true;

    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            if (this->data[j][i] !=  right.data[j][i])
                parity = false;
        }

    }

    return !parity;
}

bool Matrix::operator==(const Matrix &right) {
    bool parity = true;

    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            if (this->data[j][i] !=  right.data[j][i])
                parity = false;
        }

    }

    return parity;
}


ostream& operator<<(ostream & output, const Matrix & dat) {

    for (auto it = dat.data.begin(); it!=dat.data.end(); ++it) {
        for (auto i = (*it).begin(); i != (*it).end(); ++i) {

            cout << *i << " ";
        }
        cout << endl;
    }
}