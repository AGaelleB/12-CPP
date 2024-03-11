#include "../includes/Cure.hpp"
#include "../includes/ICharacter.hpp"

/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Cure::Cure() : AMateria("cure") {
	std::cout << "~Cure~ default constructor called" << std::endl;
	return;
}

Cure::Cure(const Cure& rhs) : AMateria(rhs._type) {
	std::cout << "~Cure~ copy constructor called" << std::endl;

	*this = rhs;
	return;
}


Cure::~Cure() {
	std::cout << RED << "~Cure~ destructor called" << RESET << std::endl;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

Cure& Cure::operator=(const Cure& rhs) {
	std::cout << "~Cure~ copy assignment operator called" << std::endl;

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
	std::cout << BOLD_WHITE << "* heals " <<  target.getName() << "’s wounds *" << RESET << std::endl;
}