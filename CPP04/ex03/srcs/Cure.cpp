#include "../includes/Cure.hpp"
#include "../includes/ICharacter.hpp"

/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Cure::Cure() : AMateria("cure") {
	// std::cout << CYAN << "~Cure~ default constructor called" << RESET << std::endl;

	this->_type = "cure";
	return;
}

Cure::Cure(const Cure& rhs) : AMateria(rhs._type) {
	// std::cout << CYAN << "~Cure~ copy constructor called" << RESET << std::endl;

	*this = rhs;
	return;
}


Cure::~Cure() {
	// std::cout << RED << "~Cure~ destructor called" << RESET << std::endl;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

Cure& Cure::operator=(const Cure& rhs) {
	// std::cout << CYAN << "~Cure~ copy assignment operator called" << RESET << std::endl;

	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

std::string const & Cure::getType() const {
	return(this->_type);
}


Cure* Cure::clone() const {
	Cure *cloneCure = new Cure(*this);
	return (cloneCure);
}


void Cure::use(ICharacter& target) {
	std::cout << "* heals" <<  target.getName() << "’s wounds *" << std::endl;
}