#include "AMateria.hpp"


AMateria::AMateria(): type("unknow") 
{
	if(PRINT)	
		std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria(const std::string& type): type(type) 
{
	if(PRINT)	
		std::cout << "AMateria constructor called" << std::endl;
}
AMateria::AMateria(const AMateria& other): type(other.type) 
{
	if(PRINT)	
		std::cout << "AMateria copy constructor called" << std::endl;
} 
AMateria& AMateria::operator=(const AMateria& other)
{
	if(PRINT)	
		std::cout << "AMateria copy assignment operator constructor called" << std::endl;
	type = other.type;
	return *this;
}
AMateria::~AMateria()
{
	if(PRINT)
		std::cout << "AMateria destructor called" << std::endl;
}

std::string const& AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter&  target)
{
		std::cout << "unknow effect for " << target.getName()<< std::endl;
}