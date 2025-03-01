#include "Point.hpp"

static Fixed calculateArea(const Point& a, const Point& b, const Point& c) {
  Fixed area = (a.getX() * (b.getY() - c.getY()) +
               b.getX() * (c.getY() - a.getY()) +
               c.getX() * (a.getY() - b.getY()));
  if (area < 0) 
  	area =  area * -1;
  return area / 2; 
}

bool bsp(const Point a, const Point b, const Point c, const Point point) 
{

  Fixed areaABC = calculateArea(a, b, c);
  Fixed areaABP = calculateArea(a, b, point);
  Fixed areaBCP = calculateArea(b, c, point);
  Fixed areaCAP = calculateArea(c, a, point);

  if (areaABP == 0 || areaBCP == 0 || areaCAP == 0) 
    return false;
  Fixed sumAreas = areaABP + areaBCP + areaCAP;
  return (sumAreas == areaABC);
}