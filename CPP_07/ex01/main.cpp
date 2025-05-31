#include "Iter.hpp"
#include <iostream>


template <typename T> 
void printElement(T& element) {
    std::cout << element << std::endl ;
}


void doubleInt(int& x) {
    x *= 2;
}

int main() {
    
    int intArray[] = {1, 2, 3, 4, 5};
    iter(intArray, 5, printElement);  
    iter(intArray, 5, doubleInt);         
    iter(intArray, 5, printElement);  

    

	const int constArray[] = {10, 20, 30};  
    iter(constArray, 3, printElement); 

    return 0;
}