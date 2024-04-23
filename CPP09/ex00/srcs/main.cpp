#include "../includes/BitcoinExchange.hpp"
#include "../includes/Colors.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << RED << "Error: could not open file." << RESET << std::endl;
		return 1;
	}

	std::string inputFile = av[1];
	BitcoinExchange exchange(inputFile);

	exchange.loadBitcoinPrices();
	exchange.parseInputFile(inputFile);

	return 0;
}
