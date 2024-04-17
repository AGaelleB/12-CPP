#include "../includes/easyfind.hpp"

#define RED			"\033[1;31m"
#define GREEN		"\033[1;32m"
#define BLUE		"\033[1;34m"
#define BOLD		"\033[1m\033[37m"
#define RESET		"\033[0m"

int main() {

	std::cout << std::endl << GREEN << "	~~~ Vector Tests ~~~" << RESET << std::endl;


	std::cout << std::endl << BLUE << "~~ Test #1 : existing vector ~~" << RESET << std::endl;
	int arr[] = { 103, 14, -12, 123, 73, 42, 3, -55};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0])); // Initialisation du vecteur avec les éléments du tab "arr"
	std::cout << "Vector container: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		std::cout << "[" << *it << "] ";
	}
	std::cout << std::endl;

	std::cout << std::endl << BOLD << "-> Trying to find vector [42] in the container" << RESET << std::endl;
	try {
		std::vector<int>::iterator itVec = easyfind(vec, 42);
	std::cout << "Found value " << *itVec << " in vector at position: " << std::distance(vec.begin(), itVec) << std::endl;
	}
	catch (const NoOccurrenceException& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << std::endl << BLUE << "~~ Test #2 : unexisting vector ~~" << RESET << std::endl;
	int arrError[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<int> vecError(arrError, arrError + sizeof(arrError) / sizeof(arrError[0]));
	std::cout << "Vector container: ";
	for (std::vector<int>::iterator it = vecError.begin(); it != vecError.end(); it++) {
		std::cout << "[" << *it << "] ";
	}
	std::cout << std::endl;

	std::cout << std::endl << BOLD << "-> Trying to find unexisting vector [42] in the container" << RESET << std::endl;
	try {
		std::vector<int>::iterator itVecError = easyfind(vecError, 42);
	std::cout << "Found value " << *itVecError << " in vector at position: " << std::distance(vec.begin(), itVecError) << std::endl;
	}
	catch (const NoOccurrenceException& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << std::endl << BLUE << "~~ Test #3 : empty vector ~~" << RESET << std::endl;
	std::vector<int> vecEmpty; // Vecteur vide
	std::cout << "Vector container: ";
	for (std::vector<int>::iterator it = vecEmpty.begin(); it != vecEmpty.end(); it++) {
		std::cout << "[" << *it << "] ";
	}
	std::cout << std::endl;

	std::cout << std::endl << BOLD << "-> Trying to find vector [42] in the empty container" << RESET << std::endl;
	try {
		std::vector<int>::iterator itVec = easyfind(vecEmpty, 42);
		std::cout << "Value found in vector at position: " << std::distance(vecEmpty.begin(), itVec) << std::endl;
	} catch (const NoOccurrenceException& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << std::endl << BLUE << "~~ Test #4 : multiple occurence ~~" << RESET << std::endl;
	int arrMultiple[] = { 103, 42, 14, 12, 123, 73, 42, 3, 55};
	std::vector<int> vecMultiple(arrMultiple, arrMultiple + sizeof(arrMultiple) / sizeof(arrMultiple[0]));
	std::cout << "Vector container: ";
	for (std::vector<int>::iterator it = vecMultiple.begin(); it != vecMultiple.end(); it++) {
		std::cout << "[" << *it << "] ";
	}
	std::cout << std::endl;

	std::cout << std::endl << BOLD << "-> Trying to find vector [42] in the container" << RESET << std::endl;
	try {
		std::vector<int>::iterator itVec = easyfind(vecMultiple, 42);
	std::cout << "Found value " << *itVec << " in vector at position: " << std::distance(vecMultiple.begin(), itVec) << std::endl;
	}
	catch (const NoOccurrenceException& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
