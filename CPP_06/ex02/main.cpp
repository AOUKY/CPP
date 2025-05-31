# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <cstdlib>
# include <ctime>
# include <iostream>

Base* generate() {
    std::srand(std::time(0));
    int choice = std::rand() % 3;
    switch (choice) {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
    }
	return 0;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}
void identify(Base& p)
{
	try {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (std::exception&) {
        try {
            dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        } catch (std::exception&) {
            std::cout << "C" << std::endl;
        }
    }
}

int main()
{
	Base* obj = generate();
    identify(obj);     
    identify(*obj);     
    delete obj;
    return 0;
}