#include "../includes/ClapTrap.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

ClapTrap::ClapTrap() : _name("DefaultName"), _hit(10), _energy(10), _attacksDamage(0) {
	std::cout << CYAN << "~ClapTrap~ default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _energy(10), _attacksDamage(0) {
	std::cout << CYAN << "~ClapTrap~ constructor called for " << _name << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& rhs) {
	std::cout << "~ClapTrap~ copy constructor called" << std::endl;
	*this = rhs;
	return;
}

ClapTrap::~ClapTrap() {
	std::cout << RED << "~ClapTrap~ destructor called for " << _name << RESET << std::endl;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
	std::cout << "~ClapTrap~ copy assignment operator called" << std::endl;

	if (this != &rhs) { 
		this->_name = rhs._name;
		this->_hit = rhs._hit;
		this->_energy = rhs._energy;
		this->_attacksDamage = rhs._attacksDamage;
	}
	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

void ClapTrap::attack(const std::string& target) {

	if (this->_energy <= 0 || this->_hit <= 0) {
		std::cout << MAGENTA << "Sorry, ClapTrap can't attack, " << _name << " is dead\n" << RESET;
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

void ClapTrap::takeDamage(unsigned int amount) {

	if (amount > MAX_INT) {
		MSG_ERROR_ARG;
		return;
	}
	if (this->_energy <= 0 || this->_hit <= 0) {
		std::cout << MAGENTA << "Sorry, ClapTrap can't takeDamage, " << _name << " is dead\n" << RESET;
		return;
	}
	MSG_TAKE_DAMAGE;
	if (this->_hit > 0) {
		this->_hit -= amount;
	}
	if (this->_hit <= 0) {
		MSG_NO_LIFE;
		return ;
	}
	MSG_COUNT;
}

void ClapTrap::beRepaired(unsigned int amount) {

	if (this->_energy <= 0 || this->_hit <= 0) {
		std::cout << MAGENTA << "Sorry, ClapTrap can't beRepaired, " << _name << " is dead\n" << RESET;
		return;
	}
	else {
		if (amount <= MAX_INT) {
			if (this->_hit < MAX_HEALTH) {
				this->_hit += amount;
				if (this->_hit > MAX_HEALTH) 
					this->_hit = MAX_HEALTH;
			}
			if (this->_energy > 0) {
				this->_energy--;
				MSG_BE_REPAIRED
			}
			if (this->_energy <= 0) {
				MSG_NO_ENERGY;
				return ;
			}
		} else {
			MSG_ERROR_ARG;
			return ;
		}
		MSG_COUNT;
	}
}
