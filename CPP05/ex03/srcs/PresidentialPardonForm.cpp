#include "../includes/PresidentialPardonForm.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm 🧑‍⚖️", 25, 5), _target("default_target") {

	// std::cout << CYAN << "~PresidentialPardonForm~ default constructor called" << RESET << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm 🧑‍⚖️", 25, 5), _target(target) {

	// std::cout << CYAN << "~PresidentialPardonForm~ type constructor called" << RESET << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs) : AForm(rhs) {
	// std::cout << CYAN << "~PresidentialPardonForm~ copy constructor called" << RESET << std::endl;
	*this = rhs;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	// std::cout << RED << "~PresidentialPardonForm~ destructor called" << RESET << std::endl;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
	if (this != &rhs) {
		this->_target = rhs._target;
	}
	return (*this);
}

/*********************************** GETTERS **********************************/

std::string	PresidentialPardonForm::getTarget() const {
	return (this->_target);
}

/****************************** FONCTIONS MEMBRES ******************************/

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	
	if (executor.getGrade() > 5) {
		throw GradeTooLowException();
	}
	else
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox\n";
}
