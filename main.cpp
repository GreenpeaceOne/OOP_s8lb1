#include "Matrix.h"


using namespace std;

int main() {
    Complex a11(1, 1);
    Complex a12(1, 2);
    Complex a13(1, 3);
    Complex a21(2, 1);
    Complex a22(2, 2);
    Complex a23(2, 3);
    Complex a31(3, 1);
    Complex a32(3, 2);
    Complex a33(3, 3);


    Matrix m1 = {{ {a11, a12, a13},
                   {a21, a22, a23},
                   {a31, a31, a33}
                   }};

    Matrix m2 = m1;

//    Matrix m3 = m1 + m2;



    cout << m1;
    m1 = !m1;
    cout << "--------------" << endl;
    cout << m1;

}

