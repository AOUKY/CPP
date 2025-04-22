#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);

        Form topSecret("Top Secret", 1, 1);
        Form memo("Memo", 150, 150);

        std::cout << topSecret << std::endl;
        std::cout << memo << std::endl;

        boss.signForm(topSecret);

        intern.signForm(topSecret);

        intern.signForm(memo);

        Form invalid("Invalid", 0, 151);
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}