#include "../includes/Cat.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Cat::Cat() {
	std::cout << CYAN << "~Cat~ default constructor called" << RESET << std::endl;
	 this->_type = "Cat";
}

Cat::Cat(const Cat& rhs) : Animal(rhs._type) { // heritage
	*this = rhs;
	std::cout << CYAN << "~Cat~ copy constructor called" << RESET << std::endl;
	return;
}

Cat::~Cat() {
	std::cout << RED << "~Cat~ destructor called" << RESET << std::endl;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

Cat& Cat::operator=(const Cat& rhs) {
	std::cout << CYAN << "~Cat~ copy assignment operator called" << RESET << std::endl;

	if (this != &rhs) { 
		this->_type = rhs._type;
	}
	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

void	Cat::makeSound() const{
	std::cout << "\"Miaouuu\" 🐱🐈" << std::endl;

}
