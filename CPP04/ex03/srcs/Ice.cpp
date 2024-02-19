#include "../includes/Ice.hpp"
#include "../includes/ICharacter.hpp"

/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Ice::Ice() : AMateria("ice")  {
	std::cout << CYAN << "~Ice~ default constructor called" << RESET << std::endl;
	this->_type = "ice";
	return;
}

Ice::Ice(const Ice& rhs) : AMateria(rhs._type) {
	*this = rhs;
	std::cout << CYAN << "~Ice~ copy constructor called" << RESET << std::endl;
	return;
}

Ice::~Ice() {
	std::cout << RED << "~Ice~ destructor called" << RESET << std::endl;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

Ice& Ice::operator=(const Ice& rhs) {
	std::cout << CYAN << "~Ice~ copy assignment operator called" << RESET << std::endl;

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
	std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}