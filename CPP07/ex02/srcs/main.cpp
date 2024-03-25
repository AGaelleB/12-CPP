#include "../includes/Array.hpp"

#define RED			"\033[1;31m"
#define GREEN		"\033[1;32m"
#define YELLOW		"\033[1;33m"
#define BLUE		"\033[1;34m"
#define MAGENTA		"\033[1;35m"
#define CYAN		"\033[1;36m"
#define WHITE		"\033[1m\033[37m"
#define RESET		"\033[0m"

int main() {
	// Test du constructeur par défaut
	std::cout << BLUE << "-> Test du constructeur par défaut" << RESET << std::endl;
	Array<int> arr1;
	std::cout << "Size of arr1: " << arr1.getSize() << std::endl; // Devrait afficher 0

	// Test du constructeur avec un paramètre
	std::cout << BLUE << "\n-> Test du constructeur avec un paramètre" << RESET << std::endl;
	Array<int> arr2(5);
	std::cout << "Size of arr2: " << arr2.getSize() << std::endl; // Devrait afficher 5

	// Test de l'accès aux éléments du tableau
	std::cout << BLUE << "\n-> Test de l'accès aux éléments du tableau" << RESET << std::endl;
	for (unsigned int i = 0; i < arr2.getSize(); ++i) {
		arr2[i] = i * 10;
	}

	// Affichage des éléments du tableau
	std::cout << BLUE << "\n-> Affichage des éléments du tableau" << RESET << std::endl;
	std::cout << "Elements of arr2: ";
	for (unsigned int i = 0; i < arr2.getSize(); ++i) {
		std::cout << arr2[i] << " ";
	}
	std::cout << std::endl;

	// Test de la copie de tableau
	std::cout << BLUE << "\n-> Test de la copie de tableau" << RESET << std::endl;
	Array<int> arr3 = arr2; // Constructeur par copie
	std::cout << "Size of arr3 (copied from arr2): " << arr3.getSize() << std::endl; // Devrait afficher 5
	std::cout << "Elements of arr3: ";
	for (unsigned int i = 0; i < arr3.getSize(); ++i) {
		std::cout << arr3[i] << " ";
	}
	std::cout << std::endl;

	// Modification de arr2 et vérification que arr3 n'est pas affecté
	std::cout << BLUE << "\n-> Modification de arr2 et vérification que arr3 n'est pas affecté" << RESET << std::endl;
	arr2[0] = 100;
	std::cout << "Modified arr2[0] to 100" << std::endl;
	std::cout << "Elements of arr2: ";
	for (unsigned int i = 0; i < arr2.getSize(); ++i) {
		std::cout << arr2[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Elements of arr3 (should remain unchanged): ";
	for (unsigned int i = 0; i < arr3.getSize(); ++i) {
		std::cout << arr3[i] << " ";
	}
	std::cout << std::endl;

	// Test d'accès à un index hors limites
	std::cout << BLUE << "\n-> Test d'accès à un index hors limites" << RESET << std::endl;
	try {
		std::cout << "Trying to access arr2[10]..." << std::endl;
		std::cout << arr2[10] << std::endl; // Devrait lancer une exception
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
