#ifndef WrongCAT_HPP
#define WrongCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    WrongCat();
    ~WrongCat();


	WrongCat(const WrongCat& other); 
    WrongCat& operator=(const WrongCat& other); 

    void makeSound() const ;
};

#endif