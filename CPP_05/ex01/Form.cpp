# include "Bureaucrat.hpp"

Form::Form() : name("unknow"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
	std::cout << "Default constructor of the Form " << name << " called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	std::cout << "constructor of the Form " << name << " called" << std::endl;
	if(gradeToSign < 1)
		throw GradeTooHighException();
	else if(gradeToSign > 150)
		throw GradeTooLowException();
	if(gradeToExecute < 1)
		throw GradeTooHighException();
	else if(gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	std::cout << "copy constructor fo the Form " << name << " called" << std::endl;
	if(gradeToSign < 1)
		throw GradeTooHighException();
	else if(gradeToSign > 150)
		throw GradeTooLowException();
	if(gradeToExecute < 1)
		throw GradeTooHighException();
	else if(gradeToExecute > 150)
		throw GradeTooLowException();
}

Form& Form::operator=(const Form& other)
{
	if(this != &other)
		isSigned = other.isSigned;
	return *this;
}

Form::~Form()
{
	std::cout << "destructor of the Form " << name << " called" << std::endl;
}

const std::string& Form::getName() const
{
	return name;
}

bool Form::get_isSigned() const
{
	return isSigned;
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low ";
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high ";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << form.getName() << ", Form status: " << (form.get_isSigned() ? "signed" : "unsigned")
       << ", grade required to sign: " << form.getGradeToSign()
       << ", grade required to execute: " << form.getGradeToExecute();
    return os;
}
