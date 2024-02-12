#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#include <iostream>

#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define RESET	"\033[0m"

class FragTrap : virtual public ClapTrap { // FragTrap herite de ClapTrap avec virtual

	public :
		 // construteur par default, de copie et destructeur
		FragTrap();
		FragTrap(std::string _name);
		FragTrap(const FragTrap& rhs);
		~FragTrap();

		// Opérateur d'affectation, surcharge d'operateur '='
		FragTrap& operator=(const FragTrap& rhs);

		// fonctions membre
		void	attack(const std::string& target);
		void	highFivesGuys(void);
};

#endif


/* HERITAGE VIRTUEL

	virtual devant la déclaration d'héritage pour indiquer un "héritage virtuel".
	L'héritage virtuel garantit que, même si une classe est héritée plusieurs fois à
	travers différents chemins dans une hiérarchie d'héritage, il n'y aura qu'une
	seule instance de sa base.

 */