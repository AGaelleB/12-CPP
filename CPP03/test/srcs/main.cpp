#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

// int	main( void ) {

// ClapTrap claptrap("Gaga");

// claptrap.attack("Bibi");

// claptrap.beRepaired(14);
// claptrap.takeDamage(9);
// claptrap.beRepaired(100);
// claptrap.takeDamage(9);

// for (int j = 0; j < 10; ++j)
// 	claptrap.beRepaired(0);

// for (int i = 0; i < 10; ++i)
// 	claptrap.takeDamage(0);


// return 0;
// }

// int	main(void)
// {
// 	ScavTrap	tic("Tic");
// 	ScavTrap	tic2("Truc");

// 	tic2 = tic;
// 	ScavTrap	tic3(tic);

// 	std::cout << "\nTic playing\n";
// 	tic.attack("Tac");
// 	tic.takeDamage(7);
// 	tic.beRepaired(2);
// 	tic.takeDamage(5);
// 	tic.attack("Toc");
// 	tic.attack("Tuc");
// 	tic.takeDamage(33);
// 	tic.attack("Tac");
// 	tic.beRepaired(42);

	
// 	std::cout << "\nTic2 playing\n";
// 	tic2.attack("Tic");
// 	tic2.attack("Tac");
// 	tic2.attack("Toc");
// 	tic2.attack("Tic");
// 	tic2.attack("Tac");
// 	tic2.attack("Toc");
// 	tic2.attack("Tic");
// 	tic2.attack("Tac");
// 	tic2.attack("Toc");
// 	tic2.attack("Tic");

// 	tic2.attack("Tac");
// 	tic2.attack("Toc");
// 	tic2.attack("Tic");
// 	tic2.attack("Tac");

// 	tic2.guardGate();
// 	tic2.takeDamage(99);
// 	tic2.beRepaired(66);
// 	tic2.takeDamage(99);
// 	tic2.attack("Tic");

// 	std::cout << "\nTic3 playing\n";
// 	tic3.takeDamage(90);
// 	tic3.beRepaired(90);
// 	tic3.takeDamage(42);
// 	tic3.beRepaired(42);
// 	return (0);
// }

int	main(void)
{
	ScavTrap	fight1("Gaga");
	ScavTrap	fight2("Bibi");


	std::cout << "\nGaga's fight" << std::endl;
	fight1.attack("Bibi");
	fight1.takeDamage(7);
	fight1.beRepaired(2);
	fight1.takeDamage(5);
	fight1.takeDamage(90);
	fight1.attack("Bibi");
	fight1.beRepaired(42);

	
	std::cout << "\nBibi's fight" << std::endl;
	for (int i = 0; i < 5; i++)
		fight2.attack("Stone");

	fight2.guardGate();
	fight2.takeDamage(99);
	fight2.beRepaired(1);
	fight2.takeDamage(2);
	fight2.attack("Stone");

	return (0);
}