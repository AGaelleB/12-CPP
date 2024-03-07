#include "../includes/FragTrap.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

FragTrap::FragTrap() : ClapTrap() { // heritage
	std::cout << BLUE << "~FragTrap~ default constructor called" << RESET << std::endl;

	this->_name = "DefaultName";
	this->_hit = 100;
	this->_energy = 100;
	this->_attacksDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) { // heritage

	this->_name = name;
	this->_hit = 100;
	this->_energy = 100;
	this->_attacksDamage = 30;

	std::cout << BLUE << "~FragTrap~ constructor called for " << this->_name << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& rhs) : ClapTrap(rhs) { // heritage
	std::cout << "~FragTrap~ copy constructor called" << std::endl;
	*this = rhs;
	return;
}

FragTrap::~FragTrap() {
	std::cout << RED << "~FragTrap~ destructor called for " << _name << RESET << std::endl;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

FragTrap& FragTrap::operator=(const FragTrap& rhs) {
	std::cout << "~FragTrap~ copy assignment operator called" << std::endl;

	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hit = rhs._hit;
		this->_energy = rhs._energy;
		this->_attacksDamage = rhs._attacksDamage;
	}
	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

void	FragTrap::highFivesGuys() {

	if (this->_energy <= 0 || this->_hit <= 0) {
		std::cout << MAGENTA << "Sorry, ClapTrap can't do a high five, " << _name << " is dead\n" << RESET;
		return;
	}
	else
		std::cout << BOLD << "FragTrap give you a high fives 🙌 !" << RESET << std::endl;
}

