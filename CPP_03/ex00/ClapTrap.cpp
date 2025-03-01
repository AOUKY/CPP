# include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("UNKNOW") ,  hitPoints(10), energyPoints(10), attackDamage(0) {}
ClapTrap::ClapTrap(std::string name) : name(name) ,  hitPoints(10), energyPoints(10), attackDamage(0) 
{
	std::cout << "constructors called" << std::endl;
}
ClapTrap::~ClapTrap()
{
	std::cout << "destructors called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if(energyPoints && hitPoints)
	{
		std::cout << "ClapTrap " <<name<<" attacks "<<target<<", causing "<<attackDamage<<" points of damage!"<<std::endl;
		energyPoints--;
	}
	else if(!hitPoints)
		std::cout << "ClapTrap " <<name<<" died!"<<std::endl;
	else
		std::cout << "ClapTrap " <<name<<"dons't have energy points!"<<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(energyPoints && hitPoints)
	{
		std::cout << "ClapTrap " <<name<<"repairing "<<amount<<" of hit points!"<<std::endl;
		hitPoints += amount;
		energyPoints--;
	}
	else if(!hitPoints)
		std::cout << "ClapTrap " <<name<<" died!"<<std::endl;
	else
		std::cout << "ClapTrap " <<name<<"dons't have energy points!"<<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(!hitPoints)
	{
		hitPoints -= amount;
		std::cout << "ClapTrap " <<name<<" taking "<<amount<<" of damage" <<std::endl;
	}
	else
		std::cout << "ClapTrap " <<name<<" died!"<<std::endl;
	if(hitPoints < 0)
		hitPoints = 0;
	
}

std::string ClapTrap::getName() const {
    return name;
}

int ClapTrap::getHitPoints() const {
    return hitPoints;
}

int ClapTrap::getEnergyPoints() const {
    return energyPoints;
}

int ClapTrap::getAttackDamage() const {
    return attackDamage;
}


void ClapTrap::setName(const std::string& newName) {
    name = newName;
}

void ClapTrap::setHitPoints(int newHitPoints) {
    hitPoints = newHitPoints;
}

void ClapTrap::setEnergyPoints(int newEnergyPoints) {
    energyPoints = newEnergyPoints;
}

void ClapTrap::setAttackDamage(int newAttackDamage) {
    attackDamage = newAttackDamage;
}