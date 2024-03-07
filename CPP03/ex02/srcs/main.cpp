#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"


int	main(void) {
	FragTrap	fight1("Gaga");
	FragTrap	fight2("Bibi");

	ClapTrap	fight3("zzz");
	std::cout << "\n	~~~ sdfgsdfgsdfg's fight ~~~" << std::endl;
	fight3.attack("sfgdfgdsgdf");
	fight3.takeDamage(7);
	fight3.beRepaired(2);
	fight3.takeDamage(5);
	fight3.takeDamage(90);
	fight3.attack("sdfgdsfgsdfgsdfg");
	fight3.beRepaired(42);

	std::cout << "\n	~~~ Gaga's fight ~~~" << std::endl;
	fight1.attack("a Zombie");
	fight1.takeDamage(7);
	fight1.beRepaired(2);
	fight1.highFivesGuys();
	fight1.takeDamage(5);
	fight1.takeDamage(90);
	fight1.attack("a Zombie");
	fight1.beRepaired(42);
	fight1.highFivesGuys();

	std::cout << "\n\n	~~~ Bibi's fight ~~~" << std::endl;
	for (int i = 0; i < 5; i++)
		fight2.attack("a stone");
	fight2.highFivesGuys();
	fight2.takeDamage(99);
	fight2.beRepaired(1);
	fight2.highFivesGuys();
	fight2.takeDamage(2);
	fight2.attack("a stone");

	std::cout << std::endl;

	// for (int i = 0; i < 10; i++)
	// 	fight1.attack("Bibi");

	// for (int i = 0; i < 10; i++)
	// 	fight1.takeDamage(0);

	// for (int i = 0; i < 10; i++)
	// 	fight1.beRepaired(0);

	return (0);
}
