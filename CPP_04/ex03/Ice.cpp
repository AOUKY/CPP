# include "Ice.hpp"


Ice::Ice(): AMateria("ice") 
{
	if(PRINT)	
		std::cout << "Ice Default constructor called" << std::endl;
}

Ice::Ice(const Ice& other)
{
	(void)other;
	if(PRINT)	
		std::cout << "Ice copy constructor called" << std::endl;
} 
Ice& Ice::operator=(const Ice& other)
{
	(void)other;
	if(PRINT)	
		std::cout << "Ice copy assignment operator constructor called" << std::endl;
	return *this;
}
Ice::~Ice()
{
	if(PRINT)
		std::cout << "Ice destructor called" << std::endl;
}

void Ice::use(ICharacter&  target)
{
		std::cout << "* shoots an ice bolt at "<<target.getName()<<" *" << std::endl;
}

Ice* Ice::clone() const
{
	return (new Ice());
}