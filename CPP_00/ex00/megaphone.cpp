#include <iostream>

void uper(char *v)
{
	int i;
	
	i = 0;
	while (v[i])
	{
		if(v[i] >= 'a' && v[i] <= 'z')
			std::cout << (char)(v[i] - 32) ;
		else
			std::cout << v[i];
		i++;
	}
}
int main(int c, char **v)
{
	int i;

	i = 1;
	if(c == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (v[i])
		uper(v[i++]);
	std::cout << std::endl;
}