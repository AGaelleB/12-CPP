#include "Zombie.hpp"

int main() {

	// creation d'un zombie dans la stack (la pile)
	randomChump("Zombie Gaga de la Stack");

	// creation d'un zombie dans la heap (le tas)
	Zombie *ZombiePtr;
	ZombiePtr = newZombie("Zombie Bibi de la Heap");
	delete ZombiePtr;

	return 0;
}


/*
Zombie sur la pile (stack) :
	myZombie sera détruit automatiquement lorsque la fonction main se termine.
	Ils sont alloués et libérés automatiquement.

Zombie sur le tas (heap) :
	L'objet persiste tant qu'il n'est pas libéré explicitement en utilisant delete.
	newZombiePtr doit être libéré avec delete pour éviter les fuites de mémoire.
 */