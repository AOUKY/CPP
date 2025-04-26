# include "RobotomyRequestForm.hpp"
# include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45), target("unknown")
{
	if(PRINT)
		std::cout << "Robotomy Request Form Default constructor called." << std::endl;
}
	
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request", 72, 45), target(target)
{
	if(PRINT)
		std::cout << "Robotomy Request Form constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target)
{
	if(PRINT)
		std::cout << "Robotomy Request Form copy constructor called." << std::endl;
}

RobotomyRequestForm&  RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	if(PRINT)
		std::cout << "Destructor called for Robotomy Request Form." << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat& exec) const
{
	if(!get_isSigned())
		throw FormNotSignedException();
	else if(exec.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	std::cout << "*** DRILLING NOISES *** Bzzzzzzzzzzzt! ***" << std::endl;
	std::srand(std::time(0)); 
	if(std::rand() % 2)
		std::cout << target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << target << ". The subject escaped." << std::endl;
}