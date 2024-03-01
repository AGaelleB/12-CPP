#include "../includes/ScalarConverter.hpp"



// int	main(int ac, char **av)
// {
// 	if (ac != 2)
// 	{
// 		std::cout << "Please enter one number\n";
// 		return 1;
// 	}
// 	std::cout << BLUE << "\n******* Conversion of \""<< av[1] <<"\" *******\n" << RESET << std::endl;
// 	std::string	to_convert = static_cast<std::string>(av[1]);
// 	ScalarConverter::convert(to_convert);
// 	return 0;
// }

int main() {
    ScalarConverter::convert("42");
    ScalarConverter::convert("42.0f");
    ScalarConverter::convert("-42.0");
    ScalarConverter::convert("nanf");
    ScalarConverter::convert("-inf");
    ScalarConverter::convert("'c'");
    ScalarConverter::convert("");
    ScalarConverter::convert("99999999999999999999999999999999999999"); // Out of range for int
    ScalarConverter::convert("3.4028235e+38f"); // Out of range for float
    ScalarConverter::convert("1.7976931348623157e+308"); // Out of range for double
    ScalarConverter::convert("a"); // Non-numeric input
    ScalarConverter::convert("test"); // Non-numeric input
    return 0;
}
