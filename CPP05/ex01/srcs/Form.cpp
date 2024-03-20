#include "../includes/Form.hpp"
#include "../includes/main.hpp"

/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Form::Form() : _nameForm("Form0"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << CYAN << "~Form~ default constructor called" << RESET << std::endl;
	return;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute): _nameForm(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << CYAN << "~Form~ type constructor called" << RESET << std::endl;

	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw (GradeTooHighException());
	else if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw (GradeTooLowException());

	return;
}


Form::Form(const Form& rhs) : _nameForm(rhs._nameForm), _isSigned(rhs._isSigned), _gradeToSign(rhs._gradeToSign), _gradeToExecute(rhs._gradeToExecute) {
	std::cout << CYAN << "~Form~ copy constructor called" << RESET << std::endl;
	return;
}

Form::~Form() {
	std::cout << RED << "~Form~ destructor called" << RESET << std::endl;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

Form& Form::operator=(const Form& rhs) {
	std::cout << CYAN << "~Form~ copy assignment operator called" << RESET << std::endl;

	if (this == &rhs)
		return (*this);
	this->_isSigned = rhs._isSigned;

	return (*this);
}


/*********************************** GETTERS **********************************/

std::string	Form::getNameForm() const {
	return (this->_nameForm);
}

bool	Form::getIsSigned() const {
	return (this->_isSigned);
}

int	Form::getGradeToSign() const {
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute() const {
	return (this->_gradeToExecute);
}


/****************************** FONCTIONS MEMBRES ******************************/

void	Form::beSigned(const Bureaucrat& bureaucrat) {

	if (bureaucrat.getGrade() > this->_gradeToSign) {
		throw (GradeTooLowException());
	}
	else {
		std::cout << bureaucrat.getName() << " signed \"" << this->_nameForm << "\"" <<std::endl;
		
		this->_isSigned = true;
	}

}

/*************************** OPERATEUR D'INSERTION ****************************/

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << WHITE << "\n~~~~ FORM INFO ~~~~\n" << RESET;
	os << "Form name : " << form.getNameForm() \
	<< "\nForm grade to sign: " << form.getGradeToSign() \
	<< "\nForm grade to execute: " << form.getGradeToExecute();

	if (form.getIsSigned() == true)
		os << "\nForm status : is signed";
	else if (form.getIsSigned() == false)
		os << "\nForm status : is not signed";

	return os;
}