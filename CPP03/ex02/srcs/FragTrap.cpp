#include "../includes/FragTrap.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

FragTrap::FragTrap() : ClapTrap() { // heritage
	std::cout << BLUE << "~FragTrap~ default constructor called" << RESET << std::endl;

	this->_hit = 100;
	this->_energy = 100;
	this->_attacksDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) { // heritage
	std::cout << BLUE << "~FragTrap~ constructor called for " << this->_name << RESET << std::endl;

	this->_hit = 100;
	this->_energy = 100;
	this->_attacksDamage = 30;
}

FragTrap::FragTrap(const FragTrap& rhs) : ClapTrap(rhs) { // heritage
	*this = rhs;
	std::cout << "~FragTrap~ copy constructor called" << std::endl;
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

void FragTrap::attack(const std::string& target) {

	if (this->_energy <= 0 || this->_hit <= 0) {
		std::cout << "Sorry, FragTrap " << _name << " is dead.\n";
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

void	FragTrap::highFivesGuys() {
	std::cout << "FragTrap give you a high fives 🙌 !" << std::endl;
}

