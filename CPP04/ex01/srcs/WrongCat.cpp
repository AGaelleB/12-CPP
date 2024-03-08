#include "../includes/WrongCat.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << BLUE << "~WrongCat~ default constructor called" << RESET << std::endl;
	 this->_type = "WrongCat";
}

WrongCat::WrongCat(std::string type) : WrongAnimal("WrongCat") {
	std::cout << BLUE << "~WrongCat~ default constructor called" << RESET << std::endl;
	 this->_type = type;
}

WrongCat::WrongCat(const WrongCat& rhs) : WrongAnimal(rhs._type) {
	*this = rhs;
	std::cout << BLUE << "~WrongCat~ copy constructor called" << RESET << std::endl;
	return;
}

WrongCat::~WrongCat() {
	std::cout << RED << "~WrongCat~ destructor called" << RESET << std::endl;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
	std::cout << BLUE << "~WrongCat~ copy assignment operator called" << RESET << std::endl;

	if (this != &rhs) { 
		this->_type = rhs._type;
	}
	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

void	WrongCat::makeSound() const{
	std::cout << "\"Shhhhhhhhh\" 🐱🐈" << std::endl;

}
