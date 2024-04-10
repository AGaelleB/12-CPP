#include "../includes/ScalarConverter.hpp"



int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Please enter one number\n";
		return 1;
	}
	std::cout << BLUE << "\n******* Conversion of \""<< av[1] <<"\" *******\n" << RESET << std::endl;
	std::string	to_convert = static_cast<std::string>(av[1]);
	ScalarConverter::convert(to_convert);
	return 0;
}
