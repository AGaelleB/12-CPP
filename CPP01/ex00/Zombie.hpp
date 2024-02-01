#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {

	private :
		std::string _name;

	public :
		Zombie(std::string name);
		~Zombie();
		void	announce(void);
};


// En plaçant ces fonctions hros de la classe, je peux faire un nbre arbitraire de zombies
// tout en ayant la possibilité de les personnaliser indiv en leur attribuant un nom et un message
// permet une separation entre la création et la manipulation des zombies.

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif