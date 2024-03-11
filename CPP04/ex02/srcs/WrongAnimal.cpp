#include "../includes/WrongAnimal.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

WrongAnimal::WrongAnimal() {
	std::cout << BLUE << "~WrongAnimal~ default constructor called" << RESET << std::endl;
	this->_type = "Am I a WrongAnimal?";
}

WrongAnimal::WrongAnimal(const std::string type) {
	std::cout << BLUE << "~WrongAnimal~ type constructor called" << RESET << std::endl;
	this->_type = type;
	return;
}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs) {
	*this = rhs;
	std::cout << BLUE << "~WrongAnimal~ copy constructor called" << RESET << std::endl;
	return;
}

WrongAnimal::~WrongAnimal() {
	std::cout << RED << "~WrongAnimal~ destructor called" << RESET << std::endl;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
	std::cout << BLUE << "~WrongAnimal~ copy assignment operator called" << RESET << std::endl;

	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

std::string WrongAnimal::getType() const {
	return (this->_type);
}

void	WrongAnimal::makeSound() const {
	std::cout << "...Bzzzz..." << std::endl;
}
