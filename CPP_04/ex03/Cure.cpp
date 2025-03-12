# include "Cure.hpp"


Cure::Cure(): AMateria("cure") 
{
	if(PRINT)	
		std::cout << "Cure Default constructor called" << std::endl;
}

Cure::Cure(const Cure& other)
{
	(void)other;
	if(PRINT)	
		std::cout << "Cure copy constructor called" << std::endl;
} 
Cure& Cure::operator=(const Cure& other)
{
	(void)other;
	if(PRINT)	
		std::cout << "Cure copy assignment operator constructor called" << std::endl;
	return *this;	
}
Cure::~Cure()
{
	if(PRINT)
		std::cout << "Cure destructor called" << std::endl;
}

void Cure::use(ICharacter&  target)
{
		std::cout << "* heals "<<target.getName()<<"’s wounds *" << std::endl;
}

Cure* Cure::clone() const
{
	return (new Cure());
}