#include "../includes/HumanA.hpp"
#include "../includes/Weapon.hpp"

#include <iostream>


/********************************* CONST ET DEST **********************************/

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
	return ;
}

HumanA::~HumanA() {
}


/************************************ FONCTION ************************************/

void	HumanA::attack() {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

