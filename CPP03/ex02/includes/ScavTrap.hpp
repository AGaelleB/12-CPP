#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#include <iostream>

#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define BOLD	"\033[1;37m"
#define RESET	"\033[0m"

class ScavTrap : public ClapTrap { // ScavTrap herite de ClapTrap

	public :
		 // construteur par default, de copie et destructeur
		ScavTrap();
		ScavTrap(std::string _name);
		ScavTrap(const ScavTrap& rhs);
		~ScavTrap();

		// Opérateur d'affectation, surcharge d'operateur '='
		ScavTrap& operator=(const ScavTrap& rhs);

		// fonctions membre
		void	attack(const std::string& target);
		void	guardGate();
};

#endif
