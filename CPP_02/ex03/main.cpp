#include "Point.hpp"
#include <iostream>

int main( void ) 
{
	Point a(0,3);
	Point b(3,0);
	Point c(0,0);
	Point p(1,1);
	if(bsp(a,b,c,p))
		std::cout<< "true"<<std::endl;
	else
		std::cout<< "false" <<std::endl;
		
	return 0;
}
