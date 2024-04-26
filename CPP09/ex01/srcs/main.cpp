#include "../includes/RPN.hpp"
#include "../includes/Colors.hpp"


int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}

	std::string numbers = av[1];
	RPN RPNCalculator(numbers);

	try {
		RPNCalculator.parsing(numbers);
		RPNCalculator.calculate(numbers);
	} catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
