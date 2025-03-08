# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"

int main()
{
	{

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; 
	delete i; 
	}

	{

	const int size = 4;
    Animal* animals[size];

    for (int i = 0; i < size; i++) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < size; i++) {
        delete animals[i]; 
    }
	}
}


