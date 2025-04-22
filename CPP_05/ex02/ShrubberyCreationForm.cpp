# include"ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("unknow")
{
	if(PRINT)
		std::cout << "Default constructor called for ShrubberyCreationForm ." << std::endl;
}
	
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137),target(target)
{
	if(PRINT)
		std::cout << "constructor called for ShrubberyCreationForm ." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target)
{
	if(PRINT)
		std::cout << "copy constructor called for ShrubberyCreationFomr" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	if(PRINT)
		std::cout << "Destructor called for ShrubberyCreationForm." << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if(!get_isSigned())
		throw FormNotSignedException();
	else if(executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	std::ofstream outfile((target + "_shrubbery").c_str());
	if(!outfile.is_open())
	{
		std::cerr << "the file fail to open "<< std::endl;
		return ;
	}
    outfile << "          .     .  .      +     .      .          ." << std::endl
            << "     .       .      .     #       .           ." << std::endl
            << "        .      .         ###            .      .      ." << std::endl
            << "      .      .   \"#:. .:##\"##:. .:#\"  .      ." << std::endl
            << "          .      . \"####\"###\"####\"  ." << std::endl
            << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       ." << std::endl
            << "  .             \"#########\"#########\"        .        ." << std::endl
            << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       ." << std::endl
            << "     .     .  \"#######\"\"##\"##\"\"#######\"                  ." << std::endl
            << "                .\"##\"#####\"#####\"##\"           .      ." << std::endl
            << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     ." << std::endl
            << "      .     \"#######\"##\"#####\"##\"#######\"      .     ." << std::endl
            << "    .    .     \"#####\"\"#######\"\"#####\"    .      ." << std::endl
            << "            .     \"      000      \"    .     ." << std::endl
            << "       .         .   .   000     .        .       ." << std::endl
            << ".. .. ..................O000O........................ ...... ..." << std::endl;
    outfile.close();
}
