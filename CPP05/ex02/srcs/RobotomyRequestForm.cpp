#include "../includes/RobotomyRequestForm.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

RobotomyRequestForm::RobotomyRequestForm() : _nameRobotomyRequestForm("RobotomyRequestForm0"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
	// std::cout << CYAN << "~RobotomyRequestForm~ default constructor called" << RESET << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& name, int gradeToSign, int gradeToExecute): _nameRobotomyRequestForm(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	// std::cout << CYAN << "~RobotomyRequestForm~ type constructor called" << RESET << std::endl;

	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw (GradeTooHighException());
	else if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw (GradeTooLowException());

	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) {
	// std::cout << CYAN << "~RobotomyRequestForm~ copy constructor called" << RESET << std::endl;
	*this = rhs;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	// std::cout << RED << "~RobotomyRequestForm~ destructor called" << RESET << std::endl;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	// std::cout << CYAN << "~RobotomyRequestForm~ copy assignment operator called" << RESET << std::endl;

	this->_nameRobotomyRequestForm = rhs._nameRobotomyRequestForm;
	this->_isSigned = rhs._isSigned;
	this->_gradeToSign = rhs._gradeToSign;
	this->_gradeToExecute = rhs._gradeToExecute;

	return (*this);
}


/*********************************** GETTERS **********************************/

std::string	RobotomyRequestForm::getNameRobotomyRequestForm() const {
	return (this->_nameRobotomyRequestForm);
}

bool	RobotomyRequestForm::getIsSigned() const {
	return (this->_isSigned);
}

int	RobotomyRequestForm::getGradeToSign() const {
	return (this->_gradeToSign);
}

int	RobotomyRequestForm::getGradeToExecute() const {
	return (this->_gradeToExecute);
}


/****************************** FONCTIONS MEMBRES ******************************/

void	RobotomyRequestForm::beSigned(const Bureaucrat& bureaucrat) {

	if (bureaucrat.getGrade() > this->_gradeToSign) {
		throw (GradeTooLowException());
	}
	else {
		std::cout << bureaucrat.getName() << " signed \"" << this->_nameRobotomyRequestForm << "\"" <<std::endl;
		
		this->_isSigned = true;
	}

}

/*************************** OPERATEUR D'INSERTION ****************************/

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& RobotomyRequestForm) {
	os << "\n~~ RobotomyRequestForm INFO ~~\n";
	os << "RobotomyRequestForm name : " << RobotomyRequestForm.getNameRobotomyRequestForm() \
	<< "\nRobotomyRequestForm grade to sign: " << RobotomyRequestForm.getGradeToSign() \
	<< "\nRobotomyRequestForm grade to execute: " << RobotomyRequestForm.getGradeToExecute();

	if (RobotomyRequestForm.getIsSigned() == true)
		os << "\nRobotomyRequestForm status : is signed";
	else if (RobotomyRequestForm.getIsSigned() == false)
		os << "\nRobotomyRequestForm status : is not signed";

	return os;
}