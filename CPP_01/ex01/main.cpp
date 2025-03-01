# include "Zombie.hpp"


int main()
{
	Zombie* zombie;
	int n;
	int i;

	n = 5;
	i = 0;
	zombie = zombieHorde( n , "zo");
	while (i < n)
	{
		zombie[i].announce();
		i++;
	}
	delete[] zombie;
}