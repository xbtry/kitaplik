#include "matrix.h"
#include <iostream>
int main()
{
    Matrix<float> a(2,3);
    float mata[6] = {1,2,3,4,5,6};
    float matb[6] = {7,8,9,10,11,12};
    a.putArray(mata);
    a.printMat();
    
    Matrix<float> b(3,2);
    b.putArray(matb);
    b.printMat();

    Matrix<float> c(2,2);
    c.printMat();

    c = a*b;
    c.printMat();

    system("pause");
}