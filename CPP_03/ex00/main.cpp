# include "ClapTrap.hpp"

int main()
{
	ClapTrap a("hamza");
	// ClapTrap b("bhamza");
	// ClapTrap c("chamza");
	// ClapTrap d("dhamza");

	a.setAttackDamage(20);
	a.attack("somoe");
	a.takeDamage(20);
	a.beRepaired(8);
	a.attack("somoe");
	std::cout<< "hilt :"<<a.getHitPoints()<<" energy: "<<a.getEnergyPoints()<<" takied damge"<<a.getAttackDamage()<<std::endl;
	
	// b.setAttackDamage(2);
	// b.attack("bsomoe");
	// b.takeDamage(10);
	// b.beRepaired(10);
	// std::cout<< "hilt :"<<b.getHitPoints()<<" energy: "<<b.getEnergyPoints()<<" takied damge"<<b.getAttackDamage()<<std::endl;
}