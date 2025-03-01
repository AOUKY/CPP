# include "Harl.hpp"

int main(int c, char **v)
{
	if(c != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems. ]" << std::endl;
		return 0;
	}
	Harl harl;

	harl.complain(v[1]);
}