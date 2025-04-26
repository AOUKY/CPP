# include "Intern.hpp"
# include "Bureaucrat.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

Intern::Intern() 
{
	if(PRINT)
		std::cout << "Intern Default constructor called." << std::endl;
}

Intern::~Intern()
{
	if(PRINT)
		std::cout << "Intern destructor called." << std::endl;
}

Intern::Intern(const Intern& other)
{
	if (PRINT)
		std::cout << "Intern Copy constructor called." << std::endl;
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void) other;
	return *this;
}


AForm* Intern::makeForm(std::string formName, std::string target) {
    std::string formTypes[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    for (int i = 0; i < 3; i++) {
        if (formName == formTypes[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            switch (i) {
                case 0: return new ShrubberyCreationForm(target);
                case 1: return new RobotomyRequestForm(target);
                case 2: return new PresidentialPardonForm(target);
            }
        }
    }
    std::cout << "Intern failed to create " << formName 
              << ": unknown form type" << std::endl;
    return 0;
}
