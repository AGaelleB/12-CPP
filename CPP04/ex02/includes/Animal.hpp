#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define RESET	"\033[0m"

class AAnimal { // AAnimal n'est plus instanciable, prefix "A"

	protected :
		std::string _type;

	public :
		 // construteur par default, de copie et destructeur
		AAnimal();
		AAnimal(std::string const type);
		AAnimal(const AAnimal& rhs);
		virtual ~AAnimal();

		// Opérateur d'affectation, surcharge d'operateur '='
		AAnimal& operator=(const AAnimal& rhs);

		// fonctions membres
		std::string		getType() const;
		virtual void	makeSound() const = 0; // déclarée virtual pour permettre le polymorphisme, mise a 0 pour classe abstraite

};

#endif


/* Methode pure, classe non instanciable prefix "A"
	
	Avec "virtual void	makeSound() const = 0;" la classe devient abstraite, c'est a dire que l'on ne peux plus l'instancier.

	Pour resumer :
	Certain comportement sont definies et d autres non, la classe abstraite ne peut etre instancié.
	Pour etre instancier une classe qui herite de cette classe abstraite (ex : Dog ou Cat) va devoir implementer les 
	comportements qui sont definis comme abstraits dans la calsse parent. Sinon ca restera abstrait et on ne pourra pas
	l'instancier. 

 */