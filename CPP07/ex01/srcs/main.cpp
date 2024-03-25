#include "../includes/iter.hpp"

#define RED			"\033[1;31m"
#define GREEN		"\033[1;32m"
#define YELLOW		"\033[1;33m"
#define BLUE		"\033[1;34m"
#define MAGENTA		"\033[1;35m"
#define CYAN		"\033[1;36m"
#define WHITE		"\033[1m\033[37m"
#define RESET		"\033[0m"

int main(void) {

	int intArray[] = {1, 2, 3, 4, 5};
	std::cout << BLUE << "Printing intArray elements:\n" << RESET;
	iter(intArray, 5, printElement<int>);
	std::cout << std::endl << std::endl;
	
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::cout << BLUE << "Printing doubleArray elements:\n" << RESET;
	iter(doubleArray, 5, printElement<double>);
	std::cout << std::endl << std::endl;

	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	std::cout << BLUE << "Printing charArray elements:\n" << RESET;
	iter(charArray, 5, printElement<char>);
	std::cout << std::endl << std::endl;

	std::string stringArray[] = {"clavier", "table", "chaise", "dell", "cluster"};
	std::cout << BLUE << "Printing stringArray elements:\n" << RESET;
	iter(stringArray, 5, printElement<std::string>);
	std::cout << std::endl << std::endl;

	return 0;
}
