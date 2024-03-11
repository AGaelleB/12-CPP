#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public AAnimal {

	private :
		Brain	*_brain; // ici permet d'acceder a brain

	public :
		 // construteur par default, de copie et destructeur
		Dog();
		Dog(const Dog& rhs);
		~Dog();

		// Opérateur d'affectation, surcharge d'operateur '='
		Dog& operator=(const Dog& rhs);

		// fonctions membres
		void	makeSound() const;
		Brain*	getBrain(void) const;
		void	setBrain(std::string idea);

};

#endif


/* Pointeur vers Brain

	Le pointeur vers Brain dans les classes Dog et Cat permet une gestion dynamique	de la mémoire.
	Gestion dynamique de la mémoire : En utilisant un pointeur vers Brain, on peut créer
	et détruire l'objet Brain dynamiquement à l'aide des opérateurs new et delete.

 */