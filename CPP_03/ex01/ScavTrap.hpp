# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
public:
	ScavTrap();
	ScavTrap& operator=(const ScavTrap& other);
	ScavTrap(const std::string &name);
	~ScavTrap();

	void attack(const std::string& target); 
    void guardGate();
};