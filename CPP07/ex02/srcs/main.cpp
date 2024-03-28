#include "../includes/Array.hpp"

#define BLUE		"\033[1;34m"
#define RESET		"\033[0m"
#define MAX_VAL		42

int main() {

	std::cout << BLUE << "-> Test du constructeur par défaut" << RESET << std::endl;
	Array<int> array1;
	std::cout << "Size of array1: " << array1.getSize() << std::endl; // affichera 0


	std::cout << BLUE << "\n-> Test du constructeur avec un paramètre" << RESET << std::endl;
	Array<int> array2(11);
	std::cout << "Size of array2: " << array2.getSize() << std::endl; // affichera 11


	std::cout << BLUE << "\n-> Test de l'accès aux éléments du tableau" << RESET << std::endl;
	for (unsigned int i = 0; i < array2.getSize(); i++) {
		array2[i] = i * 10;
	}


	std::cout << BLUE << "\n-> Affichage des éléments du tableau array2" << RESET << std::endl;
	std::cout << "Elements of array2: ";
	for (unsigned int i = 0; i < array2.getSize(); i++) {
		std::cout << array2[i] << " ";
	}
	std::cout << std::endl;


	std::cout << BLUE << "\n-> Test de la copie de tableau" << RESET << std::endl;
	Array<int> array3 = array2; // Constructeur par copie
	std::cout << "Size of array3 (copied from array2): " << array3.getSize() << std::endl; // affichera 11
	std::cout << "Elements of array3: ";
	for (unsigned int i = 0; i < array3.getSize(); i++) {
		std::cout << array3[i] << " ";
	}
	std::cout << std::endl;


	std::cout << BLUE << "\n-> Modification de array2 et vérification que array3 n'est pas affecté" << RESET << std::endl;
	array2[0] = 42;
	std::cout << "Modified array2[0] to 42" << std::endl;
	std::cout << "\nElements of array2: ";
	for (unsigned int i = 0; i < array2.getSize(); i++) {
		std::cout << array2[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Elements of array3: "; // ne changera pas car copié avant
	for (unsigned int i = 0; i < array3.getSize(); i++) {
		std::cout << array3[i] << " ";
	}
	std::cout << std::endl;


	std::cout << BLUE << "\n-> Test d'accès à un index hors limites" << RESET << std::endl;
	try {
		std::cout << "Trying to access array2[MAX_VAL]" << std::endl;
		std::cout << array2[MAX_VAL] << std::endl; // rentre dans l'exception
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}


	return 0;
}



/* 
// main du sujet
#include <cstdlib> // Pour rand() et srand()
#include <ctime>   // Pour time()

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
}
 */