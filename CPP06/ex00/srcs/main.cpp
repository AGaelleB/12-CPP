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

/* 

./convert 42
./convert 42.0f
./convert -42.0
./convert nanf
./convert -inf
./convert +inf
./convert 'c'
./convert ""
./convert 99999999999999999999999999999999999999
./convert 3.4028235e+38f								// error mais je pense c ok
./convert -3.4028235e+38f								// error mais je pense c ok
./convert 1.7976931348623157e+308						// error mais je pense c ok
./convert -1.7976931348623157e+308						// error mais je pense c ok
./convert 4.9406564584124654e-324						// error mais je pense c ok
./convert -4.9406564584124654e-324						// error mais je pense c ok
./convert a
./convert test
./convert -0.0000000000012345678901234567890
./convert 0.0000000000012345678901234567890
./convert $$$$$$$$$										// je fais un truc bizare
./convert $$$$$$$$$123									// je fais un truc bizare

 */

