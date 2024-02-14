#include "../includes/Animal.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

AAnimal::AAnimal() {
	std::cout << CYAN << "~Abstract Animal~ default constructor called" << RESET << std::endl;
	return;
}

AAnimal::AAnimal(std::string const type) : _type(type) {
	std::cout << CYAN << "~Abstract Animal~ type constructor called" << RESET << std::endl;
	return;
}

AAnimal::AAnimal(const AAnimal& rhs) {
	*this = rhs;
	std::cout << CYAN << "~Abstract Animal~ copy constructor called" << RESET << std::endl;
	return;
}

AAnimal::~AAnimal() {
	std::cout << RED << "~Abstract Animal~ destructor called" << RESET << std::endl;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

AAnimal& AAnimal::operator=(const AAnimal& rhs) {
	std::cout << CYAN << "~Abstract Animal~ copy assignment operator called" << RESET << std::endl;

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
