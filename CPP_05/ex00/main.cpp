#include "Bureaucrat.hpp"
#include <iostream>

void testInvalidCreation() {
    std::cout << "\n=== Invalid Creation Test ===\n";
    
    try {
        Bureaucrat tooHigh("TooHigh", 0);
        std::cerr << "✗ Shouldn't reach here (too high)\n";
    }
    catch (std::exception& e) {
        std::cout << "✓ Caught: " << e.what() << std::endl;
    }
    
    try {
        Bureaucrat tooLow("TooLow", 151);
        std::cerr << "✗ Shouldn't reach here (too low)\n";
    }
    catch (std::exception& e) {
        std::cout << "✓ Caught: " << e.what() << std::endl;
    }
}

void testGradeModification() {
    std::cout << "\n=== Grade Modification Test ===\n";
    
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << "Initial: " << bob << std::endl;
        
        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;
        
        bob.incrementGrade();
        std::cerr << "✗ Shouldn't reach here (increment)\n";
    }
    catch (std::exception& e) {
        std::cout << "✓ Caught: " << e.what() << std::endl;
    }
    
    try {
        Bureaucrat alice("Alice", 149);
        std::cout << "Initial: " << alice << std::endl;
        
        alice.decrementGrade();
        std::cout << "After decrement: " << alice << std::endl;
        
        alice.decrementGrade();
        std::cerr << "✗ Shouldn't reach here (decrement)\n";
    }
    catch (std::exception& e) {
        std::cout << "✓ Caught: " << e.what() << std::endl;
    }
}

int main() {
    testInvalidCreation();
    testGradeModification();
    
    return 0;
}