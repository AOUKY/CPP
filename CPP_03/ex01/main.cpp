# include "ScavTrap.hpp"

int main()
{
	
	ScavTrap a(" A ");
	// ScavTrap b(" B ");
	// ScavTrap c(" C ");
	// ScavTrap d(" D ");

	std::cout<< "hilt :"<<a.getHitPoints()<<" energy: "<<a.getEnergyPoints()<<" takied damge "<<a.getAttackDamage()<<std::endl;
	a.setAttackDamage(10);
	std::cout<< "hilt :"<<a.getHitPoints()<<" energy: "<<a.getEnergyPoints()<<" takied damge "<<a.getAttackDamage()<<std::endl;
	a.attack("somoe");
	std::cout<< "hilt :"<<a.getHitPoints()<<" energy: "<<a.getEnergyPoints()<<" takied damge "<<a.getAttackDamage()<<std::endl;
	a.takeDamage(9 );
	std::cout<< "hilt :"<<a.getHitPoints()<<" energy: "<<a.getEnergyPoints()<<" takied damge "<<a.getAttackDamage()<<std::endl;
	a.beRepaired(8);
	std::cout<< "hilt :"<<a.getHitPoints()<<" energy: "<<a.getEnergyPoints()<<" takied damge "<<a.getAttackDamage()<<std::endl;
	
	// b.setAttackDamage(2);
	// b.attack("bsomoe");
	// b.takeDamage(10);
	// b.beRepaired(10);
	// std::cout<< "hilt :"<<b.getHitPoints()<<" energy: "<<b.getEnergyPoints()<<" takied damge"<<b.getAttackDamage()<<std::endl;
}