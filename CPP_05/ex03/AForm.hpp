#ifndef AFORM_HPP
# define AFORM_HPP


#include <iostream>

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
public:
    AForm(); 
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();
    
    
    class GradeTooHighException;
    class GradeTooLowException;
    class FormNotSignedException;

    const std::string& getName() const;
    bool get_isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);
    
    virtual void execute(Bureaucrat const & executor) const = 0;
};


class AForm::GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
};

class AForm::FormNotSignedException : public std::exception {
    public:
        const char* what() const throw();
};

class AForm::GradeTooLowException : public std::exception {
public:
	 const char* what() const throw();
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif