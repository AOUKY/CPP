#include "Point.hpp"
#include <iostream>

int main( void ) 
{
	Point a(0,0);
	Point b(0,4);
	Point c(4,0);
	Point p(0.01f,0.01f);
	if(bsp(a,b,c,p))
		std::cout<< "true"<<std::endl;
	else
		std::cout<< "false" <<std::endl;
		
	return 0;
}
