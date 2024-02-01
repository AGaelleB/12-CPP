#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"
#include "../includes/Weapon.hpp"

#include <iostream>

/* 
	il est plus judicieux d'utiliser un "*" sur weapon si a un moment le player
	peut ne pas avoir de waepon (NULL).

	il est plus judicieux d'utiliser une "&" sur weapon si le player
	a tjrs une arme.

	Donc pour Bob il vaut mieux une "&" et pour Jim il vaut un "*"
 */

int main() {
	{
		Weapon	club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << std::endl;
	{
		HumanB jim("Jim");
		jim.attack(); // test pour pointeur vers NULL, jim n'a pas encore de weapon

		Weapon	club = Weapon("crude spiked club");

		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}

