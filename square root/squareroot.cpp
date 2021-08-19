#include <iostream>

// x^2 - n = y formülü
float f(float x, float n)
{
  float y = (x * x) - n;
  return y;
}

//xc = xi + 1
//xi = xi

float fv(float xi,float n)
{
  float xc = xi - f(xi,n)/(2*xi); // f(xi,n) = y değeri, f'(xi) = 2*xi türev değeri.
  return xc; // xi+1i döndür
}

float getRoot(float num)
{
  float n = num;
  float xi = n; // rastgele bir değerden başlaması için
  float xc;

  for (int i = 0; i < 10; i++)
  {
    xc = fv(xi,n);
    xi = xc;
  }

  return xc;
}

int main()
{
  std::cout << getRoot(2);
}
