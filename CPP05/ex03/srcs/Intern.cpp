#include "../includes/Intern.hpp"
#include "../includes/main.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Intern::Intern() : AForm("Intern 🧑‍⚖️", 25, 5), _target("default_target") {

	std::cout << CYAN << "~Intern~ default constructor called" << RESET << std::endl;
	return;
}

Intern::Intern(const std::string& target) : AForm("Intern 🧑‍⚖️", 25, 5), _target(target) {

	std::cout << CYAN << "~Intern~ type constructor called" << RESET << std::endl;
	return;
}

Intern::Intern(const Intern& rhs) : AForm(rhs) {
	std::cout << CYAN << "~Intern~ copy constructor called" << RESET << std::endl;
	*this = rhs;
	return;
}

Intern::~Intern() {
	std::cout << RED << "~Intern~ destructor called" << RESET << std::endl;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

Intern& Intern::operator=(const Intern& rhs) {
	if (this != &rhs) {
		this->_target = rhs._target;
	}
	return (*this);
}

// /*********************************** GETTERS **********************************/

// std::string	Intern::getTarget() const {
// 	return (this->_target);
// }

/****************************** FONCTIONS MEMBRES ******************************/

void	Intern::makeForm() const {
	
	
}
