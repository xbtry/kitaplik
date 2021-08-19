#include <iostream>
#include <cmath>
#define PI 3.14159265


class Vec4 {};

class Vec2{
  float x;
  float y;
public:

  Vec2(){}
  Vec2(float x,float y) : x(x), y(y) {}

  Vec2 operator+(const Vec2& v){
    Vec2 obj;
    obj.x = this->x + v.x;
    obj.y = this->y + v.y;
    return obj;
  };
  Vec2 operator-(const Vec2& v){
    Vec2 obj;
    obj.x = this->x - v.x;
    obj.y = this->y - v.y;
    return obj;
  };
  Vec2 operator*(const Vec2& v){
    Vec2 obj;
    obj.x = this->x * v.x;
    obj.y = this->y * v.y;
    return obj;
  };

  float length(){
    float ret = sqrt((x*x)+(y*y));
    return ret;
  };

  Vec2 u(){
    Vec2 obj;
    obj.x = x * (1/(length()));
    obj.y = y * (1/(length()));
    return obj;
  };

  void rotate(float angle)
  {
    Vec2 obj;
    obj.x = (x*cos(angle)) - (y*sin(angle));
    obj.y = (x*sin(angle)) + (y*cos(angle));
    x = obj.x;
    y = obj.y;
  };
  
  float det(const Vec2& b)
  { 
    float determinant = (x * b.y) - (b.x * y);
    return determinant; 
  };

  float dotpr(Vec2 &b)
  {
    float cos = ( (x*b.x) + (y*b.y) ) / ( length() * b.length() );
    return cos;
  };

  void print(){
    std::cout << "2D Vector X[" << this->x << "],Y[" << this->y << "]" << '\n';
  };
  
  Vec2 normal()
  {
    float x2 = x;
    float y2;
    if (y != 0)
      y2 = (x*x) / y;
    else
      y2 = 1;
    Vec2 obj;
    obj.x = x2;
    obj.y = y2;
    obj.print();
    obj = obj.u();
    return obj;
  };
};