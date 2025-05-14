# include "ScalarConverter.hpp"
# include <limits>
# include <cmath>
#include <iomanip>

ScalarConverter::ScalarConverter() {	
	std::cout << "ScalarConverter default constructur called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
	std::cout << "ScalarConverter copy constructur called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { 
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter destructur called" << std::endl;
}

bool ScalarConverter::isChar(const std::string& str)
{
	char c;

	if(str.length() != 1 || (str[0] >= '0' && str[0] <= '9') || !(str[0] >= 32 && str[0] <= 126))
		return false;
	c = str[0];
	std::cout << "char : '" << c << "'" << std::endl;
	std::cout << "int : " << static_cast<int>(c) << std::endl;
	std::cout << "float : " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(c)  << std::endl;
	return true;
}

bool ScalarConverter::isInt(const std::string& str)
{
	long n;
	char *end;

	if(str.find('.') != std::string::npos || str.find('f') != std::string::npos)
		return false; 
	n = strtol(str.c_str(), &end, 10);
	if(*end != 0 || n > INT_MAX || n < INT_MIN)
		return false; 
	int nb = n;
	if(nb >= 32 && nb <= 126)
		std::cout << "char : '" << static_cast<char>(nb) << "'" <<std::endl;
	else if(nb > 127 || nb < -128)
		std::cout << "char : impossible" << std::endl;
	else
		std::cout << "char :  Non displayable" << std::endl;
	std::cout << "int : " << nb << std::endl;
	std::cout << "float : " << static_cast<float>(nb) << std::endl;
	std::cout << "double : " << static_cast<double>(nb) << std::endl;
	return true;
}
bool ScalarConverter::isEmpty(const char* str) 
{
    if (str == 0) 
		return true; 
    return std::string(str).find_first_not_of(' ') == std::string::npos;
}

bool ScalarConverter::isFloat(const std::string& str)
{
	float f;
	char *end;
	if(str.find('f') == std::string::npos || str.find('.') == std::string::npos)
		return false; 
	f = strtof(str.c_str(), &end);
	if(*end != 'f' || !isEmpty(&end[1]))
	{
		std::cerr << "this is invalid number" << std::endl;
		return true;
	}
	if(f >= 32 && f <= 126)
		std::cout << "char : '" << static_cast<char>(f) << "'" << std::endl;
	else if(f > 127 || f < -128)
		std::cout << "char : impossible" << std::endl;
	else
		std::cout << "char :  Non displayable" << std::endl;
	if(f > INT_MAX || f < INT_MIN)
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(f) << std::endl;
	if(f == std::numeric_limits<float>::infinity())
		std::cout << "float : +inff" << std::endl;
	else
		std::cout << "float : " << f << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(f) << std::endl;
	return true;
}
bool ScalarConverter::isDouble(const std::string& str)
{
	double f;
	char *end;
	f = strtod(str.c_str(), &end);
	if(!isEmpty(end))
	{
		std::cerr << "this is invalid number" << std::endl;
		return true;
	}
	if(f >= 32 && f <= 126)
		std::cout << "char : '" << static_cast<char>(f) << "'" << std::endl;
	else if(f > 127 || f < -128)
		std::cout << "char : impossible" << std::endl;
	else
		std::cout << "char :  Non displayable" << std::endl;
	if(f > INT_MAX || f < INT_MIN)
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(f) << std::endl;
	if(f > std::numeric_limits<float>::max())
		std::cout << "float : +inff" << std::endl;
	else
		std::cout << "float : " << static_cast<float>(f) << "f" << std::endl;
	if(f == std::numeric_limits<double>::infinity())
		std::cout << "double : +inf" << std::endl;
	else
		std::cout << "double : " << f << std::endl;
	return true;
}

void ScalarConverter::printing_special(std::string str)
{
	std::cout << "char : impossible" << std::endl;
	std::cout << "int : impossible" << std::endl;
	std::cout << "float : " << str << "f" << std::endl;
	std::cout << "double : " << str << std::endl;
}

bool ScalarConverter::isSpecial(const std::string& str)
{
	std::string special_type[] = {"inf", "+inf", "inff", "+inff", "-inf", "-inff", "nan", "nanf"};;
	
	for (int i = 0; i < 8; i++)
	{
		if(special_type[i] == str)
		{
			if(i <= 3)
				printing_special("+inf");
			else if(i <= 5)
				printing_special("-inf");
			else
				printing_special("nan");
			return true;
		}
	}
	return false;
}

void ScalarConverter::convert(const std::string& str)
{
	bool (*types[5])(const std::string&) = {
        &ScalarConverter::isSpecial,
        &ScalarConverter::isChar,
        &ScalarConverter::isInt,
        &ScalarConverter::isFloat,
        &ScalarConverter::isDouble
    };
	std::cout << std::fixed << std::setprecision(1);
	for(int i = 0; !(types[i](str)); i++)
		;
}

