// #include "../includes/ClapTrap.hpp"
#include "../includes/DiamondTrap.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

DiamondTrap::DiamondTrap() {
	std::cout << BLUE << "~DiamondTrap~ default constructor called" << RESET << std::endl;
}


DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name) {
	std::cout << BLUE << "~DiamondTrap~ constructor called for " << this->_name << RESET << std::endl;
	
	this->_hit = FragTrap::_hit; // Hérité de FragTrap
	this->_energy = ScavTrap::_energy; // Hérité de ScavTrap
	this->_attacksDamage = FragTrap::_attacksDamage; // Hérité de FragTrap
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

	if (this->_energy <= 0 || this->_hit <= 0) {
		std::cout << "Sorry, DiamondTrap " << _name << " is dead.\n";
		return; 
	}
	else {
		if (this->_energy > 0)
			this->_energy--;	
		if (this->_energy <= 0) {
			MSG_NO_ENERGY;
			return ;
		}
		MSG_ATTACK;
	}
	MSG_COUNT;
}

void	DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name is " << this->_name;
	std::cout << " and my ClapTrap name is " << ClapTrap::_name << std::endl;

}

