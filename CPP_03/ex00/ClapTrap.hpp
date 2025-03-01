#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
class ClapTrap{
private:
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;
public:
	// the ClapTrap instances should not interact directly with one another, 
	// and the parameters will not refer to another instance of ClapTrap.|check copy==
	ClapTrap(std::string name);
	ClapTrap();
	~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

	std::string getName() const;
    int getHitPoints() const;
    int getEnergyPoints() const;
    int getAttackDamage() const;

    void setName(const std::string& name);
    void setHitPoints(int hitPoints);
    void setEnergyPoints(int energyPoints);
    void setAttackDamage(int attackDamage);
};

#endif
