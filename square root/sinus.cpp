#include <iostream>


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

float Sin(float rad)
{
  float d = 0;
  for(int i = 0; i < 500; i++)
  {
    d += (usAl(-1,i) * 1/fakt((2*i)+1)) * usAl(rad,(2*i)+1);
  }
  std::cout << d << '\n';
  return d;
}

int main()
{
  Sin(0.78539816339);
}
