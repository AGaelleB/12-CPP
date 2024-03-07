#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"

int	main(void) {
	ClapTrap	fight1("Gaga");
	ScavTrap	fight2("Bibi");
	FragTrap	fight3("Tom");
	DiamondTrap	fight4("Sun");
	DiamondTrap	fightDefault;

	std::cout << "\n	~~~ Default's fight ~~~" << std::endl;
	fightDefault.attack("something");
	fightDefault.takeDamage(7);

	std::cout << "\n	~~~ Gaga's fight ~~~" << std::endl;
	fight1.attack("a Zombie");
	fight1.takeDamage(7);
	fight1.beRepaired(2);
	fight1.takeDamage(5);
	fight1.takeDamage(90);
	fight1.attack("a Zombie");
	fight1.beRepaired(42);

	std::cout << "\n	~~~ Bibi's fight ~~~" << std::endl;
	for (int i = 0; i < 5; i++)
		fight2.attack("a stone");
	fight2.guardGate();
	fight2.takeDamage(99);
	fight2.beRepaired(1);
	fight2.takeDamage(2);
	fight2.attack("a stone");
	fight2.guardGate();

	std::cout << "\n	~~~ Tom's fight ~~~" << std::endl;
	fight3.highFivesGuys();
	for (int i = 0; i < 5; i++)
		fight3.attack("a door");
	fight3.highFivesGuys();
	fight3.takeDamage(42);
	fight3.beRepaired(24);
	fight3.takeDamage(42);
	fight3.attack("a door");
	fight3.highFivesGuys();


	std::cout << "\n	~~~ Sun's fight ~~~" << std::endl;
	fight4.whoAmI();
	fight4.takeDamage(42);
	fight4.beRepaired(24);
	fight4.takeDamage(24);
	fight4.takeDamage(420);
	fight4.beRepaired(42);
	fight4.whoAmI();

	std::cout << std::endl;

	// for (int i = 0; i < 10; i++)
	// 	fight1.attack("Bibi");

	// for (int i = 0; i < 10; i++)
	// 	fight1.takeDamage(0);

	// for (int i = 0; i < 10; i++)
	// 	fight1.beRepaired(0);

	return (0);
}
