#include "../includes/AForm.hpp"
#include "../includes/main.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

 AForm:: AForm() : _nameForm(" AForm0"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << CYAN << "~AForm~ default constructor called" << RESET << std::endl;
	return;
}

 AForm:: AForm(const std::string& name, int gradeToSign, int gradeToExecute): _nameForm(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << CYAN << "~AForm~ type constructor called" << RESET << std::endl;

	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw (GradeTooHighException());
	else if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw (GradeTooLowException());

	return;
}


 AForm:: AForm(const  AForm& rhs) : _nameForm(rhs._nameForm), _isSigned(rhs._isSigned), _gradeToSign(rhs._gradeToSign), _gradeToExecute(rhs._gradeToExecute) {
	std::cout << CYAN << "~AForm~ copy constructor called" << RESET << std::endl;
	return;
}

AForm::~AForm() {
	std::cout << RED << "~AForm~ destructor called" << RESET << std::endl;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

 AForm&  AForm::operator=(const  AForm& rhs) {
	std::cout << CYAN << "~ AForm~ copy assignment operator called" << RESET << std::endl;

	if (this == &rhs)
		return (*this);
	this->_isSigned = rhs._isSigned;

	return (*this);
}

/*********************************** GETTERS **********************************/

std::string	AForm::getNameForm() const {
	return (this->_nameForm);
}

bool	AForm::getIsSigned() const {
	return (this->_isSigned);
}

int	AForm::getGradeToSign() const {
	return (this->_gradeToSign);
}

int	AForm::getGradeToExecute() const {
	return (this->_gradeToExecute);
}


/****************************** FONCTIONS MEMBRES ******************************/

void	AForm::beSigned(const Bureaucrat& bureaucrat) {

	if (bureaucrat.getGrade() > this->_gradeToSign) {
		throw (GradeTooLowException());
	}
	else {
		if (this->_isSigned == true)
			std::cout << bureaucrat.getName() << " try to sign form \"" << this->_nameForm << "\" but it's already signed" <<std::endl;
		else {
			std::cout << bureaucrat.getName() << " signed \"" << this->_nameForm << "\"" <<std::endl;
			this->_isSigned = true;
		}
	}
}

/*************************** OPERATEUR D'INSERTION ****************************/

std::ostream& operator<<(std::ostream& os, const AForm& AForm) {
	os << WHITE << "\n~~~~ FORM INFO ~~~~\n" << RESET;
	os << "Form name : " << AForm.getNameForm() \
	<< "\nForm grade to sign: " << AForm.getGradeToSign() \
	<< "\nForm grade to execute: " << AForm.getGradeToExecute();

	if (AForm.getIsSigned() == true)
		os << "\nForm status : is signed ✅";
	else if (AForm.getIsSigned() == false)
		os << "\nForm status : is not signed ❌";

	return os;
}