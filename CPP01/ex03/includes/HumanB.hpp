#include "../includes/Weapon.hpp"

#ifndef HUMANB_H
#define HUMANB_H

#include <iostream>


class HumanB {

	private :
		std::string	_name;
		Weapon* _weapon; // Pointeur à Waepon

	public :
		HumanB(std::string name);
		~HumanB();

		//setter
		void	setWeapon(Weapon &weapon);

		// fonction
		void	attack(void);

};

#endif