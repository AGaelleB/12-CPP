#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal {

	public :
		 // construteur par default, de copie et destructeur
		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat& rhs);
		~WrongCat();

		// Opérateur d'affectation, surcharge d'operateur '='
		WrongCat& operator=(const WrongCat& rhs);

		// fonctions membres
		void	makeSound() const;
};

#endif
