#include "Array.hpp"

#include <iostream>

int main()
{
	try{
	Array<int> a;
	Array<int> b(5);
	//test
	b[1] = 2;
	for(size_t i = 0; i < b.size(); i++)
		std::cout << b[i] << std::endl;
	}
	catch(std::exception& e){
			std::cout << e.what() << std::endl;
	}
}
