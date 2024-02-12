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
#define RESET	"\033[0m"

#define MSG_ATTACK		std::cout << YELLOW << "ClapTrap " << _name << " attacks " << target << ", causing " << _attacksDamage << " points of damage! " << RESET << std::endl;
#define MSG_TAKE_DAMAGE	std::cout << RED << "ClapTrap " << _name << " took damage for " << amount << " points!" << RESET << std::endl;
#define MSG_BE_REPAIRED	std::cout << GREEN << "ClapTrap " << _name << " is repaired for " << amount << " points and gained 1 point of energy! " << RESET << std::endl;
#define MSG_COUNT		std::cout << _hit << "/100 health, " << _energy << "/100 energy points!" << std::endl;
#define MSG_NO_LIFE		std::cout << MAGENTA << "ClapTrap " << _name << " is dead, she had no life points left ... RIP :'( " << RESET << std::endl;
#define MSG_NO_ENERGY	std::cout << MAGENTA << "ClapTrap " << _name << " is dead, she had no energy left ... RIP :'( " << RESET << std::endl;
#define MSG_ERROR_ARG	std::cout << "Amount must be positive interger" << std::endl;

#define	MAX_INT 2147483647
#define	MAX_ENERGY 100
#define	MAX_HEALTH 100


class ClapTrap {

	protected : // permet de d'acceder depuis la classe heritée
		std::string	_name;
		int			_hit;
		int			_energy;
		int			_attacksDamage;

	public :
		 // construteur par default, de copie et destructeur
		ClapTrap();
		ClapTrap(std::string _name);
		ClapTrap(const ClapTrap& rhs);
		virtual ~ClapTrap(); // Déclarer le destructeur comme virtuel pour permettre le polymorphisme

		// Opérateur d'affectation, surcharge d'operateur '='
		ClapTrap& operator=(const ClapTrap& rhs);

		// fonctions membres
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};


#endif


/* POLYMORPHISME

	Le polymorphisme en C++ permet à différentes classes dérivées d'une même classe
	de base de redéfinir les fonctions virtuelles de cette classe de base,
	leur permettant ainsi de se comporter différemment lorsqu'elles sont appelées
	via des pointeurs ou des références de la classe de base.

	En résumé, le polymorphisme permet d'utiliser un même nom de fonction pour
	différentes classes, et la fonction appelée dépendra du type réel de l'objet
	à l'exécution. Cela facilite la mise en œuvre de concepts tels que l'encapsulation,
	l'abstraction et la modularité dans le code.

	Exemple : tu as une classe qui s'appelle "Animal". Cette classe a une
	fonction appelée "MakeSound" qui fait "miaou" pour un chat, "wouf" pour
	un chien et "coin-coin" pour un canard.

	Tu décides de créer des sous-classes comme "Chat", "Chien" et "Canard" qui
	héritent de la classe "Animal". Ces sous-classes peuvent redéfinir la fonction "MakeSound"
	pour faire le bruit approprié pour chaque animal.

 */