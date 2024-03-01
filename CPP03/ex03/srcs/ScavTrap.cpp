// #include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

ScavTrap::ScavTrap() : ClapTrap("DefaultName") { // heritage
	std::cout << BLUE << "~ScavTrap~ default constructor called" << RESET << std::endl;

	this->_hit = 100;
	this->_energy = 100;
	this->_attacksDamage = 30;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) { // heritage
	std::cout << BLUE << "~ScavTrap~ constructor called for " << this->_name << RESET << std::endl;

	this->_hit = 100;
	this->_energy = 100;
	this->_attacksDamage = 30;
}

ScavTrap::ScavTrap(const ScavTrap& rhs) : ClapTrap(rhs) { // heritage
	*this = rhs;
	std::cout << "~ScavTrap~ copy constructor called" << std::endl;
	return;
}

ScavTrap::~ScavTrap() {
	std::cout << RED << "~ScavTrap~ destructor called for " << _name << RESET << std::endl;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
	std::cout << "~ScavTrap~ copy assignment operator called" << std::endl;

	if (this != &rhs) { 
		this->_name = rhs._name;
		this->_hit = rhs._hit;
		this->_energy = rhs._energy;
		this->_attacksDamage = rhs._attacksDamage;
	}
	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

void ScavTrap::attack(const std::string& target) {

	if (this->_energy <= 0 || this->_hit <= 0) {
		std::cout << "Sorry, ScavTrap " << _name << " is dead.\n";
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

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

