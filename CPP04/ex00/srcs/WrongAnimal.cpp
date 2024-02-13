#include "../includes/WrongAnimal.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

WrongAnimal::WrongAnimal() : _type("Am I a WrongAnimal?"){
	std::cout << CYAN << "~WrongAnimal~ default constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string const type) : _type(type) {
	std::cout << CYAN << "~WrongAnimal~ type constructor called" << RESET << std::endl;
	return;
}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs) {
	*this = rhs;
	std::cout << CYAN << "~WrongAnimal~ copy constructor called" << RESET << std::endl;
	return;
}

WrongAnimal::~WrongAnimal() {
	std::cout << RED << "~WrongAnimal~ destructor called" << RESET << std::endl;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
	std::cout << CYAN << "~WrongAnimal~ copy assignment operator called" << RESET << std::endl;

	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

std::string WrongAnimal::getType() const {
	return (this->_type);
}

void	WrongAnimal::makeSound() const {
	std::cout << "...Bzzzz..." << std::endl;
}
