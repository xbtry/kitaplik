#include "matrix.h"
#include <iostream>
int main()
{
    Matrix<float> a(4,4);
    float mata[16] = {1,3,5,9,1,3,1,7,4,3,9,7,5,2,0,9};
    float matb[6] = {7,8,9,10,11,12};
    a.putArray(mata);
    a.printMat();
    a.rowSwap(1,2);
    a.printMat();
    a.rowMultipx(1,2);
    a.printMat();
    a.rowAdd(1,2);
    a.printMat();
    system("pause");
}
