#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal {

	public :
		 // construteur par default, de copie et destructeur
		Dog();
		Dog(const Dog& rhs);
		~Dog();

		// Opérateur d'affectation, surcharge d'operateur '='
		Dog& operator=(const Dog& rhs);

		// fonctions membres
		void	makeSound() const;

};

#endif
