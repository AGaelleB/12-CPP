#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal {

	private :
		Brain	*_brain; // ici permet d'acceder a brain

	public :
		 // construteur par default, de copie et destructeur
		Cat();
		Cat(std::string type);
		Cat(const Cat& rhs);
		~Cat();

		// Opérateur d'affectation, surcharge d'operateur '='
		Cat& operator=(const Cat& rhs);

		// fonctions membres
		void	makeSound() const;
		Brain*	getBrain(void) const;
		void	setBrain(std::string idea);
};

#endif
