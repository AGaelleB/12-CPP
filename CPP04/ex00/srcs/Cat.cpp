#include "../includes/Cat.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Cat::Cat() : Animal("Cat") {
	std::cout << BLUE << "~Cat~ default constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat& rhs) : Animal("Cat") {
	*this = rhs;
	std::cout << BLUE << "~Cat~ copy constructor called" << RESET << std::endl;
	return;
}

Cat::~Cat() {
	std::cout << RED << "~Cat~ destructor called" << RESET << std::endl;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

Cat& Cat::operator=(const Cat& rhs) {
	std::cout << BLUE << "~Cat~ copy assignment operator called" << RESET << std::endl;

	if (this != &rhs) { 
		this->_type = rhs._type;
	}
	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

void	Cat::makeSound() const{
	std::cout << "\"Miaouuu\" 🐱🐈" << std::endl;

}
