#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {
	return ;
}

Zombie::~Zombie() {

	std::cout << this->_name << " : zombie has been destroy" << std::endl;
	return ;
}

void	Zombie::announce(void) {
	std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::setNameZombie(std::string name) {

	this->_name = name;
	return ;
}