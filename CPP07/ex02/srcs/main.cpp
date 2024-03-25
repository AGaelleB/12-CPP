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

	std::cout << BLUE << "-> Test du constructeur par défaut" << RESET << std::endl;
	Array<int>  array1;
	std::cout << "Size of  array1: " <<  array1.getSize() << std::endl; // affichera 0


	std::cout << BLUE << "\n-> Test du constructeur avec un paramètre" << RESET << std::endl;
	Array<int>  array2(11);
	std::cout << "Size of  array2: " <<  array2.getSize() << std::endl; // affichera 11


	std::cout << BLUE << "\n-> Test de l'accès aux éléments du tableau" << RESET << std::endl;
	for (unsigned int i = 0; i <  array2.getSize(); i++) {
		 array2[i] = i * 10;
	}


	std::cout << BLUE << "\n-> Affichage des éléments du tableau array2" << RESET << std::endl;
	std::cout << "Elements of  array2: ";
	for (unsigned int i = 0; i <  array2.getSize(); i++) {
		std::cout <<  array2[i] << " ";
	}
	std::cout << std::endl;


	std::cout << BLUE << "\n-> Test de la copie de tableau" << RESET << std::endl;
	Array<int>  array3 =  array2; // Constructeur par copie
	std::cout << "Size of  array3 (copied from  array2): " <<  array3.getSize() << std::endl; // affichera 11
	std::cout << "Elements of  array3: ";
	for (unsigned int i = 0; i <  array3.getSize(); i++) {
		std::cout <<  array3[i] << " ";
	}
	std::cout << std::endl;


	std::cout << BLUE << "\n-> Modification de  array2 et vérification que  array3 n'est pas affecté" << RESET << std::endl;
	 array2[0] = 42;
	std::cout << "Modified  array2[0] to 42" << std::endl;
	std::cout << "\nElements of  array2: ";
	for (unsigned int i = 0; i <  array2.getSize(); i++) {
		std::cout <<  array2[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "\nElements of  array3 (should remain unchanged): ";
	for (unsigned int i = 0; i <  array3.getSize(); i++) {
		std::cout <<  array3[i] << " ";
	}
	std::cout << std::endl;


	std::cout << BLUE << "\n-> Test d'accès à un index hors limites" << RESET << std::endl;
	try {
		std::cout << "Trying to access  array2[42]..." << std::endl;
		std::cout <<  array2[42] << std::endl; // rentre dans l'exception
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}


	return 0;
}
