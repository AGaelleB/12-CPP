#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Bureaucrat::Bureaucrat() : _name("noNameSet"), _grade(150) {
	// std::cout << CYAN << "~Bureaucrat~ default constructor called" << RESET << std::endl;
	return;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade) {
	// std::cout << CYAN << "~Bureaucrat~ type constructor called" << RESET << std::endl;

	if (this->_grade > 150)
		throw (GradeTooLowException());

	else if (this->_grade < 1)
		throw (GradeTooHighException());

	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) {
	// std::cout << CYAN << "~Bureaucrat~ copy constructor called" << RESET << std::endl;
	*this = rhs;
	return;
}

Bureaucrat::~Bureaucrat() {
	// std::cout << RED << "~Bureaucrat~ destructor called" << RESET << std::endl;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	// std::cout << CYAN << "~Bureaucrat~ copy assignment operator called" << RESET << std::endl;

	this->_name = rhs._name;
	this->_grade = rhs._grade;

	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

std::string Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::incrementGrade() {

	if (this->_grade > 1) {
		this->_grade--;
		std::cout << getName() << "'s grade incremented, it's now at grade " << getGrade() << std::endl;
	}
	else {
		throw (GradeTooHighException());
	}
}

void Bureaucrat::decrementGrade() {

	if (this->_grade < 150) {
		this->_grade++;
		std::cout << getName() << "'s grade decremented, it's now at grade " << getGrade() << std::endl;
	}
	else {
		throw (GradeTooLowException());
	}
}

void	Bureaucrat::signForm(AForm & fm) const
{
	try {
		fm.beSigned(*this);
	}

	catch (std::exception &e) {
		std::cout << getName() << " cannot sign form \"" << fm.getNameForm() << "\" because " << e.what() << std::endl;
	}
}

/*************************** OPERATEUR D'INSERTION ****************************/

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}
