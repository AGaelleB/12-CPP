#include "../includes/ClapTrap.hpp"

int	main( void ) {

ClapTrap claptrap("Gaga");

claptrap.attack("Bibi");

claptrap.beRepaired(14);
claptrap.takeDamage(9);
claptrap.beRepaired(100);
claptrap.takeDamage(9);

for (int j = 0; j < 10; ++j)
	claptrap.beRepaired(0);

for (int i = 0; i < 10; ++i)
	claptrap.takeDamage(0);


return 0;
}

