#include "../includes/Animal.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Animal::Animal() : _type("Am I a Animal?"){
	std::cout << BLUE << "~Animal~ default constructor called" << RESET << std::endl;
	return;
}

Animal::Animal(const std::string type) : _type(type) {
	std::cout << BLUE << "~Animal~ type constructor called" << RESET << std::endl;
	return;
}

Animal::Animal(const Animal& rhs) {
	*this = rhs;
	std::cout << BLUE << "~Animal~ copy constructor called" << RESET << std::endl;
	return;
}

Animal::~Animal() {
	std::cout << RED << "~Animal~ destructor called" << RESET << std::endl;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

Animal& Animal::operator=(const Animal& rhs) {
	std::cout << BLUE << "~Animal~ copy assignment operator called" << RESET << std::endl;

	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

std::string Animal::getType() const {
	return (this->_type);
}

void	Animal::makeSound() const {
	std::cout << "...No noise..." << std::endl;
}
