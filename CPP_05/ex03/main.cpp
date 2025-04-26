#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    Intern intern;
    AForm* form = intern.makeForm("robotomy request", "roto");
    if (form) {
        Bureaucrat boss("Boss", 1);
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }
    form = intern.makeForm("aaaa", "bbb");
    return 0;
}