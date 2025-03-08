# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name  + "_clap_name"),FragTrap(name + "_clap_name") , name(name) {
    energyPoints = 50;
    std::cout << "DiamondTrap " << name << " constructed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ScavTrap(other) ,FragTrap(other) , name(other.name) {
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) 
    {
        ScavTrap::operator=(other); 
        FragTrap::operator=(other); 
        name = other.name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructed!" << std::endl;
}

void DiamondTrap::whoAmI()
{
     std::cout << "I am " << name << ", and my ClapTrap name is " << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}