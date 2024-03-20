#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>
#include "../includes/main.hpp"

/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm 🌳", 145, 137), _target("default_target") {
	std::cout << CYAN << "~ShrubberyCreationForm~ default constructor called" << RESET << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm 🌳", 145, 137), _target(target) {

	std::cout << CYAN << "~ShrubberyCreationForm~ type constructor called" << RESET << std::endl;

	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) : AForm(rhs) {
	std::cout << CYAN << "~ShrubberyCreationForm~ copy constructor called" << RESET << std::endl;
	*this = rhs;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << RED << "~ShrubberyCreationForm~ destructor called" << RESET << std::endl;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	if (this != &rhs) {
		this->_target = rhs._target;
	}
	return (*this);
}

/*********************************** GETTERS **********************************/

std::string	ShrubberyCreationForm::getTarget() const {
	return (this->_target);
}

/****************************** FONCTIONS MEMBRES ******************************/

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > 137) {
		throw GradeTooLowException();
	} else {
		std::string fileName = (this->_target + "_shrubbery");
		std::ofstream outFile(fileName.c_str()); // Convert std::string to C-style string

		if (outFile.is_open()) {
			outFile << "          &&& &&  & &&\n";
			outFile << "      && &\\/&\\|& ()|/ @, &&\n";
			outFile << "      &\\/(/&/&||/& /_/)_&/_&\n";
			outFile << "   &() &\\/&|()|/&\\/ %( /_/))\n";
			outFile << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
			outFile << "&&   && & &| &| /& & % ()& /&&\n";
			outFile << " ()&_---()&\\&\\|&&-&&--%---()~\n";
			outFile << "     &&     \\|||\n";
			outFile << "             |||\n";
			outFile << "             |||\n";
			outFile << "             |||\n";
			outFile << "       , -=-~  .-^- _\n";
			outFile.close();
		} else {
			std::cerr << "Error: Could not open file for writing." << std::endl;
		}
	}
}
