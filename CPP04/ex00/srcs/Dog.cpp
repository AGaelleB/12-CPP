#include "../includes/Dog.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Dog::Dog() {
	std::cout << CYAN << "~Dog~ default constructor called" << RESET << std::endl;
	this->_type = "Dog";
	return;
}

Dog::Dog(const Dog& rhs) : Animal(rhs._type) { // heritage
	*this = rhs;
	std::cout << CYAN << "~Dog~ copy constructor called" << RESET << std::endl;
	return;
}

Dog::~Dog() {
	std::cout << RED << "~Dog~ destructor called" << RESET << std::endl;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

Dog& Dog::operator=(const Dog& rhs) {
	std::cout << CYAN << "~Dog~ copy assignment operator called" << RESET << std::endl;

	if (this != &rhs) { 
		this->_type = rhs._type;
	}
	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

void	Dog::makeSound() const {
	std::cout << "\"Waouuuf\" 🐶🐕" << std::endl;

}

