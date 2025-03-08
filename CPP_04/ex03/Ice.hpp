#include "AMateria.hpp"

class Ice : public AMateria {
public:
    Ice();
    Ice( Ice &other);
    Ice& operator=(Ice &other);
    ~Ice();
    
    AMateria* clone() const ;
    // void use(ICharacter& target) ;
};


//const here and in the amateria 🚨🚨🚨🚨🚨🚨🚨