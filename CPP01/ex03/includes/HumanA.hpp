#include "../includes/Weapon.hpp"

#ifndef HUMANA_H
#define HUMANA_H

#include <iostream>


class HumanA {

	private :
		std::string	_name;
		Weapon& _weapon; // référence à Weapon

	public :
		HumanA(std::string name, Weapon &weapon);
		~HumanA();

		// fonction
		void	attack(void);
};

#endif