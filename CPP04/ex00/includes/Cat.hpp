#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal {

	public :
		 // construteur par default, de copie et destructeur
		Cat();
		Cat(const Cat& rhs);
		~Cat();

		// Opérateur d'affectation, surcharge d'operateur '='
		Cat& operator=(const Cat& rhs);

		// fonctions membres
		void	makeSound() const;
};

#endif
