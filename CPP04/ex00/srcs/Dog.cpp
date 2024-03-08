#include "../includes/Dog.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Dog::Dog() : Animal("Dog") {
	std::cout << BLUE << "~Dog~ default constructor called" << RESET << std::endl;
	this->_type = "Dog";
	return;
}

Dog::Dog(const Dog& rhs) : Animal("Dog") {
	*this = rhs;
	std::cout << BLUE << "~Dog~ copy constructor called" << RESET << std::endl;
	return;
}

Dog::~Dog() {
	std::cout << RED << "~Dog~ destructor called" << RESET << std::endl;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

Dog& Dog::operator=(const Dog& rhs) {
	std::cout << BLUE << "~Dog~ copy assignment operator called" << RESET << std::endl;

	if (this != &rhs) { 
		this->_type = rhs._type;
	}
	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

void	Dog::makeSound() const {
	std::cout << "\"Waouuuf\" 🐶🐕" << std::endl;

}

