# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
public:
	ScavTrap();
	ScavTrap(const std::string &name);
	ScavTrap& operator=(const ScavTrap& other);
	~ScavTrap();

	void attack(const std::string& target); 
    void guardGate();
};