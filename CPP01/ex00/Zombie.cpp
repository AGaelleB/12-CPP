#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) {

	this->_name = name;
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
