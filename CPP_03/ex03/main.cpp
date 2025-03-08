# include "DiamondTrap.hpp"

int main()
{
	
	DiamondTrap a(" A ");
	// DiamondTrap b(" B ");
	// DiamondTrap c(" C ");
	// DiamondTrap d(" D ");

	a.whoAmI();
	std::cout<< "hilt :"<<a.getHitPoints()<<" energy: "<<a.getEnergyPoints()<<" takied damge "<<a.getAttackDamage()<<std::endl;
	// a.setAttackDamage(10);
	// std::cout<< "hilt :"<<a.getHitPoints()<<" energy: "<<a.getEnergyPoints()<<" takied damge "<<a.getAttackDamage()<<std::endl;
	// a.attack("somoe");
	// std::cout<< "hilt :"<<a.getHitPoints()<<" energy: "<<a.getEnergyPoints()<<" takied damge "<<a.getAttackDamage()<<std::endl;
	// a.takeDamage(9 );
	// std::cout<< "hilt :"<<a.getHitPoints()<<" energy: "<<a.getEnergyPoints()<<" takied damge "<<a.getAttackDamage()<<std::endl;
	// a.beRepaired(8);
	// std::cout<< "hilt :"<<a.getHitPoints()<<" energy: "<<a.getEnergyPoints()<<" takied damge "<<a.getAttackDamage()<<std::endl;
	a.highFivesGuys();
	a.attack("he");
	
	// b.setAttackDamage(2);
	// b.attack("bsomoe");
	// b.takeDamage(10);
	// b.beRepaired(10);
	// std::cout<< "hilt :"<<b.getHitPoints()<<" energy: "<<b.getEnergyPoints()<<" takied damge"<<b.getAttackDamage()<<std::endl;
}
