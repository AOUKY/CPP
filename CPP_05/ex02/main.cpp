#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void testShrubbery() {
    std::cout << "\n=== SHRUBBERY CREATION TEST ===\n";
    try {
        Bureaucrat gardener("Gardener", 137);
        ShrubberyCreationForm shrub("home");

        gardener.signForm(shrub);
        gardener.executeForm(shrub);  
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void testRobotomy() {
    std::cout << "\n=== ROBOTOMY REQUEST TEST ===\n";
    try {
        Bureaucrat surgeon("Surgeon", 45);
        RobotomyRequestForm robot("Bender");

        surgeon.signForm(robot);
        surgeon.executeForm(robot);  
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void testPresidential() {
    std::cout << "\n=== PRESIDENTIAL PARDON TEST ===\n";
    try {
        Bureaucrat president("President", 5);
        PresidentialPardonForm pardon("Arthur Dent");

        president.signForm(pardon);
        president.executeForm(pardon);  
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void testFailures() {
    std::cout << "\n=== FAILURE CASES TEST ===\n";
    
    
    try {
        Bureaucrat clerk("Clerk", 150);
        ShrubberyCreationForm shrub("garden");
        clerk.executeForm(shrub);  
    } catch (std::exception& e) {
        std::cerr << "Expected error: " << e.what() << std::endl;
    }

    
    try {
        Bureaucrat intern("Intern", 150);
        PresidentialPardonForm pardon("Trillian");
        intern.signForm(pardon);  
    } catch (std::exception& e) {
        std::cerr << "Expected error: " << e.what() << std::endl;
    }
}

int main() {
    testPresidential();
    testRobotomy();
    testShrubbery();
    testFailures();
    return 0;
}