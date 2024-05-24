#include "../includes/BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << RED << "Error: could not open file. Add 1 input file" << RESET << std::endl;
		return 1;
	}

	std::string inputFile = av[1];
	BitcoinExchange exchange(inputFile);

	exchange.convertionExchangeRate(inputFile);

	return 0;
}
