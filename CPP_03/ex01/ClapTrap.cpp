# include "ClapTrap.hpp"

ClapTrap::ClapTrap(const ClapTrap& other) {
    *this = other; 
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::ClapTrap() : name("UNKNOW") ,  hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap Default constructors called" << std::endl;
}
ClapTrap::ClapTrap(std::string name) : name(name) ,  hitPoints(10), energyPoints(10), attackDamage(0) 
{
	std::cout << "ClapTrap constructors called" << std::endl;
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructors called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if(energyPoints && hitPoints)
	{
		std::cout  <<"ClapTrap "<<name<<" attacks "<<target<<", causing "<<attackDamage<<" points of damage!"<<std::endl;
		energyPoints--;
	}
	else if(!hitPoints)
		std::cout  <<name<<" died!"<<std::endl;
	else
		std::cout <<name<<"dons't have energy points!"<<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(energyPoints && hitPoints)
	{
		std::cout <<name<<"repairing "<<amount<<" of hit points!"<<std::endl;
		hitPoints += amount;
		energyPoints--;
	}
	else if(!hitPoints)
		std::cout <<name<<" died!"<<std::endl;
	else
		std::cout  <<name<<"dons't have energy points!"<<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(hitPoints)
	{
		hitPoints -= amount;
		std::cout <<name<<" is taking "<<amount<<" of damage" <<std::endl;
	}
	else
		std::cout <<name<<" died!"<<std::endl;
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
    if(newHitPoints > 0)
		hitPoints = newHitPoints;
	else
		hitPoints = 0;
}

void ClapTrap::setEnergyPoints(int newEnergyPoints) {
	if(newEnergyPoints > 0)
		energyPoints = newEnergyPoints;
	else
		energyPoints = 0;
}

void ClapTrap::setAttackDamage(int newAttackDamage) {
	if(newAttackDamage > 0)
    	attackDamage = newAttackDamage;
	else 
		attackDamage = 0;
}