#include "Zombie.hpp"

void Zombie::announce( void )
{
		std::cout << get_name() << " : BraiiiiiiinnnzzzZ..."<<std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << get_name() << " : Nooo... not like this! *slumps down, eyes closing*"<<std::endl;
}

std::string Zombie::get_name( void )
{
	return (name);
}

void Zombie::set_name( std::string name)
{
	this->name = name;
}