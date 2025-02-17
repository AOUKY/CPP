#include "main.h"

bool valid_phone_number(const char *s)
{
	int i;

	i = 0;
	if(!(s[i] <= '9' && s[i] >= '0') && s[i] != '+')
		return (false);
	while (s[++i])
	{
		if(!(s[i] <= '9' && s[i] >= '0'))
		{
			return (false);			
		}
	}
	return (true);
}

bool valid_names(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if(s[i++] != ' ')
			return (true);			
	}
	return (false);
}

void write_10C(std::string &s)
{
	int i;
	int len;

	i = 0;
	len = s.length();
	if(len > 10)
	{
		while (i < 9)
		{
			std::cout<<s.at(i);
			i++;
		}
		std::cout<<".";
	}
	else
	{
		std::cout<<s;
		while (len <10)
		{
			std::cout<<" ";
			len++;
		}
	}
	std::cout<<"|";
}
void  get_info(std::string &str, std::string s,bool (*valid)(const char *))
{
	while (1)
	{
		std::cout<<s;
		std::getline(std::cin, str);
		if(valid(str.c_str()))
			break;
		else
			std::cout<< "this is not valid"<<std::endl;
	}
}
