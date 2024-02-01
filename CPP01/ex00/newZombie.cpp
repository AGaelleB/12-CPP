#include "Zombie.hpp"

Zombie *newZombie(std::string name) {

	// ici j'utilise "new" pour allouer la memoire dans la heap
	Zombie *newZombie = new Zombie(name);
	newZombie->announce();
	return (newZombie);
}
