# include "Bureaucrat.hpp"

AForm::AForm() : name("unknow"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
	if(PRINT)	
		std::cout << "Default constructor of the AForm " << name << " called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if(PRINT)	
		std::cout << "constructor of the AForm " << name << " called" << std::endl;
	if(gradeToSign < 1)
		throw GradeTooHighException();
	else if(gradeToSign > 150)
		throw GradeTooLowException();
	if(gradeToExecute < 1)
		throw GradeTooHighException();
	else if(gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	if(PRINT)	
		std::cout << "copy constructor fo the AForm " << name << " called" << std::endl;
	if(gradeToSign < 1)
		throw GradeTooHighException();
	else if(gradeToSign > 150)
		throw GradeTooLowException();
	if(gradeToExecute < 1)
		throw GradeTooHighException();
	else if(gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm& AForm::operator=(const AForm& other)
{
	if(this != &other)
		isSigned = other.isSigned;
	return *this;
}

AForm::~AForm()
{
	if(PRINT)	
		std::cout << "destructor of theAForm " << name << " called" << std::endl;
}

const std::string&AForm::getName() const
{
	return name;
}

bool AForm::get_isSigned() const
{
	return isSigned;
}

int AForm::getGradeToSign() const
{
	return gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low ";
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high ";
}
const char* AForm::FormNotSignedException::what() const throw(){
	return "Form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << form.getName() << ",AForm status: " << (form.get_isSigned() ? "signed" : "unsigned")
       << ", grade required to sign: " << form.getGradeToSign()
       << ", grade required to execute: " << form.getGradeToExecute();
    return os;
}
