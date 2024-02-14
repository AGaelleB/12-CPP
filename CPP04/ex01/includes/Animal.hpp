#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define RESET	"\033[0m"

class Animal {

	protected :
		std::string _type;

	public :
		 // construteur par default, de copie et destructeur
		Animal();
		Animal(std::string const type);
		Animal(const Animal& rhs);
		virtual ~Animal();

		// Opérateur d'affectation, surcharge d'operateur '='
		Animal& operator=(const Animal& rhs);

		// fonctions membres
		std::string		getType() const;
		virtual void	makeSound() const; // déclarée virtual pour permettre le polymorphisme

};

#endif
