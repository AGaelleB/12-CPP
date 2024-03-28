#include "../includes/Span.hpp"

#define RED			"\033[1;31m"
#define GREEN		"\033[1;32m"
#define YELLOW		"\033[1;33m"
#define BLUE		"\033[1;34m"
#define MAGENTA		"\033[1;35m"
#define CYAN		"\033[1;36m"
#define BOLD		"\033[1m\033[37m"
#define RESET		"\033[0m"


void	Subjectmain() {

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}


 void	Mymain() {

	std::cout << BLUE << "TEST #1" << RESET << std::endl;
	try {
		std::cout << BLUE << "Creating a span of 10000" << RESET << std::endl;
		Span span = Span(10000);

		std::vector<int> numbersToInsert;
		for (int i = 0; i < 10000; ++i) {
			numbersToInsert.push_back(i); // push_back car sur vector
		}

		span.addRange(numbersToInsert); // ajoue d'une serie de nb avec addRange() plutot que 1 a 1 avec addNumber

		std::cout << BOLD << "-> Printing Shortest and Longest span" << RESET << std::endl;
		std::cout << "   Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "   Longest span: " << span.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << BLUE << "\nTEST #2" << RESET << std::endl;
	try {
		std::cout << BLUE << "Creating a range of size 5 and attempting to add 10 numbers" << RESET << std::endl;
		Span span = Span(5);

		std::vector<int> numbersToInsert;
		for (int i = 0; i < 10; ++i) {
			numbersToInsert.push_back(i);
		}

		span.addRange(numbersToInsert);

		std::cout << BOLD << "-> Printing Shortest and Longest span" << RESET << std::endl;
		std::cout << "   Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "   Longest span: " << span.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << BLUE << "\nTEST #3" << RESET << std::endl;
	try {
		std::cout << BLUE << "Creating a span of size 5 and adding a just 3 numbers" << RESET << std::endl;
		Span span = Span(5);
		span.addNumber(10);
		span.addNumber(5);
		span.addNumber(15);

		std::cout << BOLD << "-> Printing Shortest and Longest span" << RESET << std::endl;
		std::cout << "   Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "   Longest span: " << span.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

int	main() {

	std::cout << BLUE << "\n	~~~ Tests subject main ~~~\n" << RESET << std::endl;
	Subjectmain();

	std::cout << BLUE << "\n	~~~ Tests my main ~~~\n" << RESET << std::endl;
	Mymain();
	return 0;
}

