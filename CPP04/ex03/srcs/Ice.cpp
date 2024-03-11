#include "../includes/Ice.hpp"
#include "../includes/ICharacter.hpp"

/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Ice::Ice() : AMateria("ice") {
	std::cout << "~Ice~ default constructor called" << std::endl;
	return;
}

Ice::Ice(const Ice& rhs) : AMateria(rhs._type) {
	std::cout << "~Ice~ copy constructor called" << std::endl;
	*this = rhs;
	return;
}

Ice::~Ice() {
	std::cout << RED << "~Ice~ destructor called" << RESET << std::endl;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

Ice& Ice::operator=(const Ice& rhs) {
	std::cout << "~Ice~ copy assignment operator called" << std::endl;

	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

std::string const & Ice::getType() const {
	return(this->_type);
}

Ice* Ice::clone() const {
	Ice *cloneIce = new Ice(*this);
	return (cloneIce);
}

void Ice::use(ICharacter& target) {
	std::cout << BOLD_WHITE << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}