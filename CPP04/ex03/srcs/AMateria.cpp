#include "../includes/AMateria.hpp"
#include "../includes/ICharacter.hpp"

/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

AMateria::AMateria() : _type("NULL") {
	std::cout << "~Abstract AMateria~ default constructor called" << std::endl;
	return;
}

AMateria::AMateria(const std::string & type) : _type(type) {
	std::cout << "~Abstract AMateria~ type constructor called" << std::endl;
	return;
}

AMateria::AMateria(const AMateria& rhs) {
	*this = rhs;
	std::cout << "~Abstract AMateria~ copy constructor called" << std::endl;
	return;
}

AMateria::~AMateria() {
	std::cout << RED << "~Abstract AMateria~ destructor called" << RESET << std::endl;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

AMateria& AMateria::operator=(const AMateria& rhs) {
	std::cout << "~Abstract AMateria~ copy assignment operator called" << std::endl;

	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

std::string const & AMateria::getType() const {
	return(this->_type);
}

void AMateria::use(ICharacter& target) {
	std::cout << BOLD_WHITE << "AMateria use on " << target.getName() << RESET << std::endl;
}