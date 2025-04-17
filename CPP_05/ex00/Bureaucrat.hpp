#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat {
private:
	const std::string name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

	const std::string& getName() const;
	int getGrade() const;

    void incrementGrade();
    void decrementGrade();

	class GradeTooHighException;
	class GradeTooLowException;
};

class Bureaucrat::GradeTooHighException : public std::exception {
public:
	virtual const char* what() const throw();	
};

class Bureaucrat::GradeTooLowException : public std::exception {
public:
	virtual const char* what() const throw();	
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif