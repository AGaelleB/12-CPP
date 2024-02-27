#include "../includes/RobotomyRequestForm.hpp"
#include <cstdlib>  // Pour rand() et srand()
#include <ctime>    // Pour time()

/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm 🔧", 72, 45), _target("default_target") { // AForm pour init les donnees

	// std::cout << CYAN << "~RobotomyRequestForm~ default constructor called" << RESET << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm 🔧", 72, 45), _target(target) {

	// std::cout << CYAN << "~RobotomyRequestForm~ type constructor called" << RESET << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) : AForm(rhs) {
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
	if (this != &rhs) {
		this->_target = rhs._target;
	}
	return (*this);
}

/*********************************** GETTERS **********************************/

std::string	RobotomyRequestForm::getTarget() const {
	return (this->_target);
}

/****************************** FONCTIONS MEMBRES ******************************/

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	
	if (executor.getGrade() > 45) {
		throw GradeTooLowException();
	}
	else {

		srand(static_cast<unsigned int>(time(0)));
		int random = rand();
		std::cout << "Robotomization in progress : Brzzzz.. Grzz.. wrrr.. 🔧\n";

		if (random % 2 == 0)
			std::cout << this->_target << " robotomization has succeeded ✅\n";
		else
			std::cout << "Oooops, sorry, robotomization of " << this->_target << " has failled ❌\n";
	}

}
