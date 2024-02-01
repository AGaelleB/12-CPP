#include "../includes/HumanB.hpp"
#include "../includes/Weapon.hpp"

#include <iostream>


/********************************* CONST ET DEST **********************************/

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
	return ;
}

HumanB::~HumanB() {
}

/************************************* SETTER *************************************/

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

/************************************ FONCTION ************************************/

void HumanB::attack() {
	if (this->_weapon) { // Protection en cas de _weapon NULL
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	}
	else
		std::cout << this->_name << " has no weapon" << std::endl;
}
