#include "../includes/Dog.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Dog::Dog() : _brain(new Brain()) { // creation du brain
	std::cout << CYAN << "~Dog~ default constructor called" << RESET << std::endl;
	this->_type = "Dog";
	return;
}

Dog::Dog(const Dog& rhs) : Animal(rhs._type), _brain(new Brain(*(rhs._brain)))  { // copie profonde du cerveau (Brain)
	*this = rhs;
	std::cout << CYAN << "~Dog~ copy constructor called" << RESET << std::endl;
	return;
}

Dog::~Dog() {
	std::cout << RED << "~Dog~ destructor called" << RESET << std::endl;
	delete _brain;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

Dog& Dog::operator=(const Dog& rhs) {
	std::cout << CYAN << "~Dog~ copy assignment operator called" << RESET << std::endl;

	this->_type = rhs._type;
	delete _brain;
	this->_brain = new Brain(*rhs._brain); // copie profonde du cerveau (Brain)

	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

void	Dog::makeSound() const {
	std::cout << "\"Waouuuf\" 🐶🐕" << std::endl;

}

Brain	&Dog::getBrain() const{
	return (*_brain);
}

