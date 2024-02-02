#include "Zombie.hpp"

void	randomChump(std::string name) {

	Zombie newZombieStack(name);
	newZombieStack.announce();

	return ;
}
