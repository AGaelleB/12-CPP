#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int	main(void) {
	ScavTrap	fight1("Gaga");
	ScavTrap	fight2("Bibi");


	std::cout << "\n	~~~ Gaga's fight ~~~" << std::endl;
	fight1.attack("Bibi");
	fight1.takeDamage(7);
	fight1.beRepaired(2);
	fight1.takeDamage(5);
	fight1.takeDamage(90);
	fight1.attack("Bibi");
	fight1.beRepaired(42);

	
	std::cout << "\n	~~~ Bibi's fight ~~~" << std::endl;
	for (int i = 0; i < 5; i++)
		fight2.attack("a stone");
	fight2.guardGate();
	fight2.takeDamage(99);
	fight2.beRepaired(1);
	fight2.takeDamage(2);
	fight2.attack("Stone");

	std::cout << std::endl;

	// for (int i = 0; i < 10; i++)
	// 	fight1.attack("Bibi");

	// for (int i = 0; i < 10; i++)
	// 	fight1.takeDamage(0);

	// for (int i = 0; i < 10; i++)
	// 	fight1.beRepaired(0);

	return (0);
}

