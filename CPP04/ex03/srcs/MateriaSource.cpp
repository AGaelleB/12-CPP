#include "../includes/MateriaSource.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

MateriaSource::MateriaSource() {
	std::cout << CYAN << "~Abstract MateriaSource~ default constructor called" << RESET << std::endl;
	return;
}

MateriaSource::MateriaSource(std::string const type) : _type(type) {
	std::cout << CYAN << "~Abstract MateriaSource~ type constructor called" << RESET << std::endl;
	return;
}

MateriaSource::MateriaSource(const MateriaSource& rhs) {
	*this = rhs;
	std::cout << CYAN << "~Abstract MateriaSource~ copy constructor called" << RESET << std::endl;
	return;
}

MateriaSource::~MateriaSource() {
	std::cout << RED << "~Abstract MateriaSource~ destructor called" << RESET << std::endl;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
	std::cout << CYAN << "~Abstract MateriaSource~ copy assignment operator called" << RESET << std::endl;

	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

std::string const & MateriaSource::getType() const {
	return(this->_type);
}


MateriaSource* MateriaSource::clone() const {

}

void MateriaSource::use(ICharacter& target) {

}