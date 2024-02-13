#include "../includes/Animal.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Animal::Animal() : _type("Am I a Animal?"){
	std::cout << CYAN << "~Animal~ default constructor called" << RESET << std::endl;
	return;
}

Animal::Animal(std::string const type) : _type(type) {
	std::cout << CYAN << "~Animal~ type constructor called" << RESET << std::endl;
	return;
}

// Animal::Animal(const Animal& rhs) {
// 	*this = rhs;
// 	std::cout << CYAN << "~Animal~ copy constructor called" << RESET << std::endl;
// 	return;
// }

Animal::Animal(const Animal& rhs) : _type(rhs._type) {
    std::cout << CYAN << "~Animal~ copy constructor called" << RESET << std::endl;
}


Animal::~Animal() {
	std::cout << RED << "~Animal~ destructor called" << RESET << std::endl;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

Animal& Animal::operator=(const Animal& rhs) {
	std::cout << CYAN << "~Animal~ copy assignment operator called" << RESET << std::endl;

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
