#include "../includes/WrongCat.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

WrongCat::WrongCat() {
	std::cout << CYAN << "~WrongCat~ default constructor called" << RESET << std::endl;
	 this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& rhs) : WrongAnimal(rhs._type) { // heritage
	*this = rhs;
	std::cout << CYAN << "~WrongCat~ copy constructor called" << RESET << std::endl;
	return;
}

WrongCat::~WrongCat() {
	std::cout << RED << "~WrongCat~ destructor called" << RESET << std::endl;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
	std::cout << CYAN << "~WrongCat~ copy assignment operator called" << RESET << std::endl;

	if (this != &rhs) { 
		this->_type = rhs._type;
	}
	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

void	WrongCat::makeSound() const{
	std::cout << "\"Shhhhhhhhh\" 🐱🐈" << std::endl;

}
