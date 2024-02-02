#include "../includes/Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: need 2 args" << std::endl;
		return (1);
	}
	Harl harl;

	harl.complain(av[1]);
	return (0);
}
