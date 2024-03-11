#include "../includes/AAnimal.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

AAnimal::AAnimal() {
	std::cout << BLUE << "~AAnimal~ default constructor called" << RESET << std::endl;
	this->_type = "Am I a Animal?";
	return;
}

AAnimal::AAnimal(const std::string type) {
	std::cout << BLUE << "~AAnimal~ type constructor called" << RESET << std::endl;
	this->_type = type;
	return;
}

AAnimal::AAnimal(const AAnimal& rhs) {
	*this = rhs;
	std::cout << BLUE << "~AAnimal~ copy constructor called" << RESET << std::endl;
	return;
}

AAnimal::~AAnimal() {
	std::cout << RED << "~AAnimal~ destructor called" << RESET << std::endl;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

AAnimal& AAnimal::operator=(const AAnimal& rhs) {
	std::cout << BLUE << "~AAnimal~ copy assignment operator called" << RESET << std::endl;

	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

std::string AAnimal::getType() const {
	return (this->_type);
}

void	AAnimal::makeSound() const {
	std::cout << "...No noise..." << std::endl;
}
