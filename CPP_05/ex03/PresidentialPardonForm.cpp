# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5) , target("unknown")
{
	if(PRINT)
		std::cout << "Presidential Pardon Form Default constructor called." << std::endl;
}
	
PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("Presidential Pardon", 25, 5), target(target)
{
	if(PRINT)
		std::cout << "Presidential Pardon Form constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) , target(other.target)
{
	if(PRINT)
		std::cout << "Presidential Pardon Form copy constructor called." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	if(PRINT)
		std::cout << "Presidential Pardon Form Destructor called." << std::endl;
}
void	PresidentialPardonForm::execute(Bureaucrat const& exec) const
{
	if(!get_isSigned())
		throw FormNotSignedException();
	else if(exec.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}