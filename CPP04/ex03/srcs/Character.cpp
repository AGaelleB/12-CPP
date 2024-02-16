#include "../includes/Charactere.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

ICharactere::ICharactere() : _items("null") {
	std::cout << CYAN << "~Charactere~ default constructor called" << RESET << std::endl;
	return;
}

ICharactere::ICharactere(std::string const type) : _type(type) {
	std::cout << CYAN << "~Charactere~ type constructor called" << RESET << std::endl;
	return;
}

ICharactere::ICharactere(const ICharactere& rhs) {
	*this = rhs;
	std::cout << CYAN << "~Charactere~ copy constructor called" << RESET << std::endl;
	return;
}

ICharactere::~ICharactere() {
	std::cout << RED << "~Charactere~ destructor called" << RESET << std::endl;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

ICharactere& ICharactere::operator=(const ICharactere& rhs) {
	std::cout << CYAN << "~Charactere~ copy assignment operator called" << RESET << std::endl;

	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/


std::string const & ICharactere::getName() const {
	
}

void ICharactere::equip(AMateria* m) {

}

void ICharactere::unequip(int idx) {

}

void ICharactere::use(int idx, ICharacter& target) {

}