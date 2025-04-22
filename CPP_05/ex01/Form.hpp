#ifndef FORM_HPP
# define FORM_HPP


#include <iostream>

class Bureaucrat;

class Form {
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
public:
    Form(); 
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    
    class GradeTooHighException;
    class GradeTooLowException;

    const std::string& getName() const;
    bool get_isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    
    void beSigned(const Bureaucrat& bureaucrat);
};


class Form::GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
};

class Form::GradeTooLowException : public std::exception {
public:
	 const char* what() const throw();
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif