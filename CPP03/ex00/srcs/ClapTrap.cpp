#include "../includes/ClapTrap.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

ClapTrap::ClapTrap() {
	std::cout << BLUE << "Default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _energy(10), _attacksDamage(0) {
	std::cout << BLUE << "Constructor called for " << _name << RESET << std::endl << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& rhs) {
	*this = rhs;
	std::cout << BLUE << "Copy constructor called" << RESET << std::endl;
	return;
}

ClapTrap::~ClapTrap() {
	std::cout << std::endl << RED << "Destructor called for " << _name << RESET << std::endl;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
	std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;

	this->_name = rhs._name;
	this->_hit = rhs._hit;
	this->_energy = rhs._energy;
	this->_attacksDamage = rhs._attacksDamage;

	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

void ClapTrap::attack(const std::string& target) {

	MSG_ATTACK;
}

void ClapTrap::takeDamage(unsigned int amount) {

	MSG_TAKE_DAMAGE
	if (this->_energy > 0 && this->_hit > 0) {
		this->_hit -= amount;
		this->_energy--;
	}
	if (this->_hit <= 0) {
		MSG_NO_LIFE;
		exit(1);
	}
	if (this->_energy <= 0) {
		MSG_NO_ENERGY;
		exit(1);
	}

	MSG_COUNT
}

void ClapTrap::beRepaired(unsigned int amount) {

	MSG_BE_REPAIRED
	if ((amount > 0 && amount <= 2147483647) || amount == 0) {
		if (this->_energy < 10 || this->_hit < 10) {
			this->_hit += amount;
			if (this->_hit > 10) 
				this->_hit = 10;
			this->_energy++;
			if (this->_energy > 10) 
				this->_energy = 10;
		}
	}
	else {
		MSG_ERROR_ARG;
		exit(1);
	}

	MSG_COUNT
}
