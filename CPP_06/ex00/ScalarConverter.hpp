#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter{
private:
	static bool isChar(const std::string& str);
	static bool isInt(const std::string& str);
	static bool isEmpty(const char* str);
	static bool isFloat(const std::string& str);
	static bool isDouble(const std::string& str);
	static void printing_special(std::string str);
	static bool isSpecial(const std::string& str);
	
public:
	ScalarConverter(); 
	ScalarConverter(const ScalarConverter& other); 
	ScalarConverter& operator=(const ScalarConverter& other); 
	~ScalarConverter(); 

	static void convert(const std::string& string);
};


#endif 

