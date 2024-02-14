#include "../includes/Cat.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Cat::Cat() : _brain(new Brain()) { // creation du brain
	std::cout << CYAN << "~Cat~ default constructor called" << RESET << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat& rhs) : Animal(rhs._type), _brain(new Brain(*(rhs._brain)))  { // copie profonde du cerveau (Brain)
	*this = rhs;
	std::cout << CYAN << "~Cat~ copy constructor called" << RESET << std::endl;
	return;
}

Cat::~Cat() {
	std::cout << RED << "~Cat~ destructor called" << RESET << std::endl;
	delete _brain;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

Cat& Cat::operator=(const Cat& rhs) { 
	std::cout << CYAN << "~Cat~ copy assignment operator called" << RESET << std::endl;

	this->_type = rhs._type;
	delete _brain;
	this->_brain = new Brain(*rhs._brain); // copie profonde du cerveau (Brain)
	
	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

void	Cat::makeSound() const{
	std::cout << "\"Miaouuu\" 🐱🐈" << std::endl;

}

Brain	&Cat::getBrain() const{
	return (*_brain);
}
