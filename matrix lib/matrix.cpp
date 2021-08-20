#include "matrix.h"
#include <iostream>
int main()
{
    Matrix<float> a(3,3);
    float mata[9] = {1,2,4,4,5,6,7,8,9};
    float matb[6] = {7,8,9,10,11,12};
    a.putArray(mata);
    std::cout << a.det();

    system("pause");
}