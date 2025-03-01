# include "Zombie.hpp"

int main()
{
	Zombie *z1;
	Zombie z;

	z1 = newZombie("zo");
	z1->announce();
	delete z1;
	z.announce();
	randomChump("zoooo");
	randomChump("");
}