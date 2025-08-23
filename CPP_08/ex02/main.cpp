#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    std::cout << "=== TESTING MUTANTSTACK ==="  << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "Elements: ";
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    
    std::cout << "=== TESTING STD::LIST ==="  << std::endl;
    std::list<int> l;
    l.push_back(5);
    l.push_back(17);
    
    std::cout << "Back: " << l.back() << std::endl;
    l.pop_back();
    std::cout << "Size: " << l.size() << std::endl;
    
    l.push_back(3);
    l.push_back(5);
    l.push_back(737);
    l.push_back(0);
    
    std::list<int>::iterator lit = l.begin();
    std::list<int>::iterator lite = l.end();
    ++lit;
    --lit;
    std::cout << "Elements: ";
    while (lit != lite) {
        std::cout << *lit << " ";
        ++lit;
    }
    std::cout << std::endl;

    return 0;
}