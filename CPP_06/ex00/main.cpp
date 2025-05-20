# include "ScalarConverter.hpp"

int main(int c, char **v)
{
	if(c != 2){
		std::cerr << "Please provide one input\n ./Converter < char, int, float or double >" << std::endl; 
		return 0;
	}
	ScalarConverter::convert(v[1]);
}