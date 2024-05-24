#include "../includes/RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}

	std::string numbers = av[1];
	RPN RPNCalculator(numbers);

	try {
		RPNCalculator.parsing(numbers);
		RPNCalculator.calculator(numbers);
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
