#include "../includes/ClapTrap.hpp"

int	main( void ) {

ClapTrap claptrap("Gaga");

claptrap.attack("Bibi");

claptrap.beRepaired(14);
claptrap.takeDamage(9);
claptrap.beRepaired(100);
claptrap.takeDamage(9);
claptrap.attack("Bibi");

for (int j = 0; j < 15; ++j)
	claptrap.beRepaired(0);

for (int i = 0; i < 10; ++i)
	claptrap.takeDamage(0);

claptrap.attack("Bibi");

return 0;
}

