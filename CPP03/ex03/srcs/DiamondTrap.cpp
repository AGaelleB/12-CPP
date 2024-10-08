#include "../includes/DiamondTrap.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

DiamondTrap::DiamondTrap() : ClapTrap("Default_name_clap_name"), FragTrap(), ScavTrap() {
	std::cout << BLUE << "~DiamondTrap~ default constructor called" << RESET << std::endl;
	
	this->_name = "DefaultName";
	this->_hit = FragTrap::_hit;
	this->_energy = ScavTrap::_energy;
	this->_attacksDamage = FragTrap::_attacksDamage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name) {
	
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->_hit = FragTrap::_hit; // Hérité de FragTrap
	this->_energy = ScavTrap::_energy; // Hérité de ScavTrap
	this->_attacksDamage = FragTrap::_attacksDamage; // Hérité de FragTrap

	std::cout << BLUE << "~DiamondTrap~ constructor called for " << this->_name << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& rhs) : ClapTrap(rhs), FragTrap(rhs), ScavTrap(rhs) { // heritage en diamant
	*this = rhs;
	std::cout << "~DiamondTrap~ copy constructor called" << std::endl;
	return;
}

DiamondTrap::~DiamondTrap() {
	std::cout << RED << "~DiamondTrap~ destructor called for " << _name << RESET << std::endl;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
	std::cout << "~DiamondTrap~ copy assignment operator called" << std::endl;

	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hit = rhs._hit;
		this->_energy = rhs._energy;
		this->_attacksDamage = rhs._attacksDamage;
	}
	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI() {

	if (this->_energy <= 0 || this->_hit <= 0) {
		std::cout << MAGENTA << "Sorry, DiamondTrap can't talk, " << _name << " is dead\n" << RESET;
		return;
	}
	else {
		std::cout << BOLD << "DiamondTrap name is " << this->_name;
		std::cout << " and my ClapTrap name is " << ClapTrap::_name << RESET << std::endl;
	}
}
