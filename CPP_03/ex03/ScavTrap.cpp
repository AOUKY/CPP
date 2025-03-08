# include "ScavTrap.hpp"

ScavTrap::ScavTrap()  
{
	std::cout << "ScavTrap Default constructors called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructors called" << std::endl;	
}
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructors called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}


ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if(this != &other)
		ClapTrap::operator=(other);
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if(energyPoints && hitPoints)
	{
		std::cout << "ScavTrap " <<name<<" attacks "<<target<<", causing "<<attackDamage<<" points of damage!"<<std::endl;
		setEnergyPoints(energyPoints - 1);
	}
	else if(!hitPoints)
		std::cout << "ScavTrap " <<name<<" died!"<<std::endl;
	else
		std::cout << "ScavTrap " <<name<<"dons't have energy points!"<<std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gatekeeper mode!" << std::endl;
}