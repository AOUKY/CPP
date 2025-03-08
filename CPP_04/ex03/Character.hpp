# include "ICharacter.hpp"

class Character : public ICharacter {
private:
    std::string name;
    AMateria* inventory[4];
public:
    Character();
    Character(std::string name);
    Character(const Character &other);
	Character& operator=(const Character &other);
    ~Character();


    void equip(AMateria* m) override;
    void unequip(int idx) override;
    void use(int idx, ICharacter& target) override;
};