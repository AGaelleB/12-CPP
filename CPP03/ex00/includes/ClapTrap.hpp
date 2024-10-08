#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <cstdlib>

#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define BOLD	"\033[1;37m"
#define RESET	"\033[0m"

#define MSG_ATTACK		std::cout << YELLOW << "ClapTrap " << _name << " attacks " << target << ", causing " << _attacksDamage << " points of damage! " << RESET << std::endl;
#define MSG_TAKE_DAMAGE	std::cout << RED << "ClapTrap " << _name << " took damage for " << amount << " points!" << RESET << std::endl;
#define MSG_BE_REPAIRED	std::cout << GREEN << "ClapTrap " << _name << " is repaired for " << amount << " points and loose 1 point of energy! " << RESET << std::endl;
#define MSG_COUNT		std::cout << _hit << " health point(s) left and " << _energy << " energy point(s) left!" << std::endl;
#define MSG_NO_LIFE		std::cout << MAGENTA << "ClapTrap " << _name << " is dead, she had no life points left ... RIP :'( " << RESET << std::endl;
#define MSG_NO_ENERGY	std::cout << MAGENTA << "ClapTrap " << _name << " can't do nothing, she had no energy left ... RIP :'( " << RESET << std::endl;
#define MSG_ERROR_ARG	std::cout << "Amount must be positive interger" << std::endl;

#define	MAX_INT 2147483647
#define	MAX_HEALTH 10

class ClapTrap {

	private :
		std::string	_name;
		int			_hit;
		int			_energy;
		int			_attacksDamage;

	public :
		 // construteur par default, de copie et destructeur
		ClapTrap();
		ClapTrap(std::string _name);
		ClapTrap(const ClapTrap& rhs);
		~ClapTrap();

		// Opérateur d'affectation, surcharge d'operateur '='
		ClapTrap& operator=(const ClapTrap& rhs);

		// fonctions membres
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};


#endif
