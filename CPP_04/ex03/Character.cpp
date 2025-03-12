# include "Character.hpp"

Character::Character() : name("unknow") 
{
	for (int i = 0; i < 4; ++i)
        inventory[i] = 0;
	if(PRINT)
		std::cout << "Character default constructor called"<<std::endl;
}

Character::Character(const std::string& name) : name(name) 
{
	for (int i = 0; i < 4; ++i)
        inventory[i] = 0;
	if(PRINT)
		std::cout << "Character default constructor called"<<std::endl;
}

 Character::Character(const Character &other)
 {
	*this = other;
 }

 Character& Character::operator=(const Character &other)
 {
	if(this != &other)
	{
		name = other.name;
		for(int i = 0; i < 4; i++)
		{
			delete inventory[i];
			if(other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = 0;	
		}
	}
	return *this;
 }



 Character::~Character()
 {
	for(int i = 0; i < 4 ; i++)
		delete inventory[i];
	head.freeList();
	if(PRINT)
		std::cout <<"Character Destructor called";
 }

 void Character::equip(AMateria *m)
 {
	if(!m)
	{
		if(PRINT)
			std::cout << "No Materia found to equip !!" << std::endl;
		return ;
	}

	for(int i = 0; i < 4; i++)
	{
		if(!inventory[i])
		{
			if(PRINT)
				std::cout << name <<" Equiped "<< m->getType() << " Materia" << std::endl;
			inventory[i] = m;
			return ;
		}
	}
	head.addMateria(m);
	std::cout<< "Inventory full !!!!!!!!"<< std::endl;
 }

 void Character::unequip(int idx)
 {
	if(idx >= 0 && idx < 4 && inventory[idx])
	{
		head.addMateria(inventory[idx]);
		if(PRINT)
			std::cout << name << " Unequiped " << inventory[idx]->getType() << " Materia" << std::endl;
	}
	else if(PRINT)
		std::cout << "No Materia found to unequip !!" << std::endl;
	inventory[idx] = 0;
 }

 void Character::use(int idx, ICharacter& target)
 {
	if(idx >= 0 && idx < 4 && inventory[idx])
		inventory[idx]->use(target);
	else
		std::cout << "No Materia found to use !!" << std::endl;
 }

 std::string const& Character::getName() const {
    return name; 
}

 
