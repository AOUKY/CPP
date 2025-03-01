#include <iostream>

int main(int c, char **v)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if(c < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (v[i])
	{
		j = 0;
		while (v[i][j])
			std::cout << (char)std::toupper(v[i][j++]);
		i++;
	}
	std::cout << std::endl;
}

