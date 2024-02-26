#include "../includes/PresidentialPardonForm.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

PresidentialPardonPresidentialPardonForm::PresidentialPardonPresidentialPardonForm() : _namePresidentialPardonForm("PresidentialPardonForm0"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
	// std::cout << CYAN << "~PresidentialPardonForm~ default constructor called" << RESET << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name, int gradeToSign, int gradeToExecute): _namePresidentialPardonForm(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	// std::cout << CYAN << "~PresidentialPardonForm~ type constructor called" << RESET << std::endl;

	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw (GradeTooHighException());
	else if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw (GradeTooLowException());

	return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs) {
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
	// std::cout << CYAN << "~PresidentialPardonForm~ copy assignment operator called" << RESET << std::endl;

	this->_namePresidentialPardonForm = rhs._namePresidentialPardonForm;
	this->_isSigned = rhs._isSigned;
	this->_gradeToSign = rhs._gradeToSign;
	this->_gradeToExecute = rhs._gradeToExecute;

	return (*this);
}


/*********************************** GETTERS **********************************/

std::string	PresidentialPardonForm::getNamePresidentialPardonForm() const {
	return (this->_namePresidentialPardonForm);
}

bool	PresidentialPardonForm::getIsSigned() const {
	return (this->_isSigned);
}

int	PresidentialPardonForm::getGradeToSign() const {
	return (this->_gradeToSign);
}

int	PresidentialPardonForm::getGradeToExecute() const {
	return (this->_gradeToExecute);
}


/****************************** FONCTIONS MEMBRES ******************************/

void	PresidentialPardonForm::beSigned(const Bureaucrat& bureaucrat) {

	if (bureaucrat.getGrade() > this->_gradeToSign) {
		throw (GradeTooLowException());
	}
	else {
		std::cout << bureaucrat.getName() << " signed \"" << this->_namePresidentialPardonForm << "\"" <<std::endl;
		
		this->_isSigned = true;
	}

}

/*************************** OPERATEUR D'INSERTION ****************************/

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& PresidentialPardonForm) {


	return os;
}