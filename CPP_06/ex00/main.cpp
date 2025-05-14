# include "ScalarConverter.hpp"

int main(int c, char **v)
{
	if(c < 2)
		std::cout << "wrong format no input" << std::endl; return 0;
	// for (int i = 1; v[i]; i++)
	// 	ScalarConverter::convert(v[i]); std::cout << "----------------------------------" << std::endl;
	ScalarConverter::convert(v[1]);
	// double d = 545.123;
	// std::cout << d << std::endl;
}