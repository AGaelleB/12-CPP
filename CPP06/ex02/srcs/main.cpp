#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include "../includes/main.hpp"


int main() {

	std::srand(std::time(0));


	std::cout << BLUE << "\n-> Generated 5 pointers" << RESET << std::endl;
	for (int i = 0; i < 5; i++)
	{
		Base* objPtr = generate();
		identify(objPtr);
		std::cout << std::endl;

		delete objPtr;
	}

	std::cout << BLUE << "-> Generated 5 references" << RESET << std::endl;
	for (int i = 0; i < 5; i++)
	{
		Base* objPtr = generate();
		Base& objRef = *objPtr;		// je stock mon ptr dans la ref pour le free a la fin
		identify(objRef);
		std::cout << std::endl;

		delete objPtr;
	}

	return 0;
}

/* 

	1. std::srand(std::time(0)); initialise le générateur de nombres aléatoires basée sur le temps actuel.

	2. Ensuite, elle génère et identifie 5 objets à l'aide de pointeurs :
		Elle affiche un message indiquant qu'elle génère 5 pointeurs.
		Elle exécute une boucle for pour créer un pointeur à chaque itération en utilisant la fonction generate().
		Elle identifie chaque objet pointé par ces pointeurs en utilisant la fonction identify().
		Elle supprime chaque objet pointé pour éviter les fuites de mémoire.
	
	3. Ensuite, elle génère et identifie 5 objets à l'aide de références :
		Elle affiche un message indiquant qu'elle génère 5 références.
		Elle exécute une autre boucle for pour créer une référence à chaque itération en utilisant la fonction generate() et en déréférençant le pointeur.
		Elle identifie chaque objet référencé en utilisant la fonction identify().


	En résumé, ce programme illustre l'utilisation de la polymorphie en C++
	pour créer, identifier, et nettoyer dynamiquement des instances de différentes classes dérivées
	à travers des pointeurs et des références, avec une gestion manuelle de la mémoire.

 */