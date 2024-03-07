#include "../includes/ClapTrap.hpp"

int	main(void) {

	ClapTrap Default;
	ClapTrap Gaga("Gaga");
	ClapTrap CopyGaga(Gaga);
	std::cout << std::endl;

	std::cout << "~~~ Gaga's fight ~~~\n" << std::endl;
	Gaga.attack("Bibi");
	Gaga.beRepaired(14);
	Gaga.takeDamage(9);
	Gaga.beRepaired(10);
	Gaga.takeDamage(9);

	for (int j = 0; j < 7; ++j)
		Gaga.beRepaired(1);

	Gaga.attack("Bibi");

	std::cout << std::endl;

	return 0;
}
