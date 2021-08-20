#ifndef MATK_LIB
#define MATK_LIB

float fakt(int sayi)
{
  if(sayi < 0 || sayi == 0)
    return 1;
  float temp = 1;
  for(int i = 1; i < sayi+1; i++)
  {
    temp *= i;
  }
  //std::cout << temp << '\n';
  return temp;
}

float usAl(float sayi, int us)
{
  float temp;
  temp = sayi;

  if (us == 0)
    return 1;

  if (us < 0)
  {
    for (int i = 0; i < -us; i++)
    {
      temp *= sayi;
    }
    temp = 1/temp;
    return temp;
  }

  for (int i = 0; i < us; i++)
  {
    temp *= sayi;
  }
  //std::cout << temp << '\n';
  return temp;
}

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

#endif