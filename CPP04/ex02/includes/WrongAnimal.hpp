#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define RESET	"\033[0m"

class WrongAnimal {

	protected :
		std::string _type;

	public :
		 // construteur par default, de copie et destructeur
		WrongAnimal();
		WrongAnimal(const std::string type);
		WrongAnimal(const WrongAnimal& rhs);
		virtual ~WrongAnimal();

		// Opérateur d'affectation, surcharge d'operateur '='
		WrongAnimal& operator=(const WrongAnimal& rhs);

		// fonctions membres
		void	makeSound() const;
		std::string		getType() const;

};

#endif
