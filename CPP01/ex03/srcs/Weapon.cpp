#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"
#include "../includes/Weapon.hpp"

#include <iostream>

Weapon::Weapon(std::string type) {
	this->setType(type);
	return ;
}

Weapon::~Weapon() {
	return ;
}

const std::string&	Weapon::getType(void) const {
	return (this->_type);
}

void	Weapon::setType(std::string type) {

	this->_type = type;
	return;
}
