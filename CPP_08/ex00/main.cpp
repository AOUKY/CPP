#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main() 
{

    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    try {
        std::vector<int>::iterator it = easyfind(vec, 2);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);

    try {   
		std::list<int>::iterator it = easyfind(lst, 42);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}