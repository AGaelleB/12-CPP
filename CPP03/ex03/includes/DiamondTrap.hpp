#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"


#include <iostream>

#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define RESET	"\033[0m"

class DiamondTrap : public FragTrap, public ScavTrap { // DiamondTrap herite de FragTrap ET ScavTrap

	private:
		std::string _name; // Nom spécifique à DiamondTrap

	public :
		 // construteur par default, de copie et destructeur
		DiamondTrap();
		DiamondTrap(std::string _name);
		DiamondTrap(const DiamondTrap& rhs);
		~DiamondTrap();

		// Opérateur d'affectation, surcharge d'operateur '='
		DiamondTrap& operator=(const DiamondTrap& rhs);

		// fonctions membre
		void	attack(const std::string& target);
		void	whoAmI();
};

#endif

/* HERITAGE EN DIAMANT

	L'héritage en diamant est un cas particulier d'héritage multiple qui se produit lorsque deux classes 
	(disons A et B) héritent d'une même classe de base (C) et qu'une quatrième classe (D) hérite
	à la fois de A et de B.

	 C
	/ \
   A   B
	\ /
	 D


 */
