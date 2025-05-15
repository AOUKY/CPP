# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("unknow") , grade(150) 
{
	if(PRINT)
		std::cout << "default constructor Bureaucrat " << name << " called" << std::endl;
}
Bureaucrat::~Bureaucrat() 
{
	if(PRINT)
		std::cout << "destructor Bureaucrat " << name << " called" << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name) , grade(other.grade) 
{
	std::cout << "copy constructor Bureaucrat " << name << " called" << std::endl;
	if(grade < 1)
		throw GradeTooHighException();
	else if(grade > 150)
		throw GradeTooLowException();
}
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) , grade(grade) 
{
	if(PRINT)
		std::cout << "constructor Bureaucrat " << name << " called" << std::endl;
	if(grade < 1)
		throw GradeTooHighException();
	else if(grade > 150)
		throw GradeTooLowException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if(this != &other)
		grade = other.grade;
	return *this;
}

const std::string& Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::incrementGrade()
{
	if(grade == 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::signForm(Form& form)
{
	try 
	{
        form.beSigned(*this); 
        std::cout << name << " signed " << form.getName() << std::endl;
    } catch (std::exception& e) 
	{
        std::cout << name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::decrementGrade()
{
	if(grade == 150)
		throw GradeTooLowException();
	grade++;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Exception : Grade is too low";
}
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Exception : Grade is too high";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) 
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}