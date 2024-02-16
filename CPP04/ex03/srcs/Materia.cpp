#include "../includes/Materia.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

AMateria::AMateria() : _type("NULL") {
	std::cout << CYAN << "~Abstract Materia~ default constructor called" << RESET << std::endl;
	return;
}

AMateria::AMateria(std::string const type) : _type(type) {
	std::cout << CYAN << "~Abstract Materia~ type constructor called" << RESET << std::endl;
	return;
}

AMateria::AMateria(const AMateria& rhs) {
	*this = rhs;
	std::cout << CYAN << "~Abstract Materia~ copy constructor called" << RESET << std::endl;
	return;
}

AMateria::~AMateria() {
	std::cout << RED << "~Abstract Materia~ destructor called" << RESET << std::endl;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

AMateria& AMateria::operator=(const AMateria& rhs) {
	std::cout << CYAN << "~Abstract Materia~ copy assignment operator called" << RESET << std::endl;

	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

std::string const & AMateria::getType() const {
	return(this->_type);
}

// pas d'implementation car AMateria est une classe abstraite
// ces fonctions seront definies dans Ice et Cure
AMateria* AMateria::clone() const {
}

// pas d'implementation car AMateria est une classe abstraite
// ces fonctions seront definies dans Ice et Cure
void AMateria::use(ICharacter& target) {
}