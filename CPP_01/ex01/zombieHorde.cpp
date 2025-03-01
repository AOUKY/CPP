# include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	int i;
	Zombie* zombie;

	if (N <= 0)
	{
		std::cout << "set a valid number(n > 0)"<< std::endl;
		return nullptr;
	}
	zombie = new Zombie[N];
	i = 0;
	while (i < N)
	{
		zombie[i].set_name(name);
		i++;
	}
	return (zombie);
}