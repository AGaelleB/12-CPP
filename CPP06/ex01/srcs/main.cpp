#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"
#include "../includes/main.hpp"


int main() {
	// Création d'un objet Data avec une valeur spécifique pour son membre
	Data myData;
	myData.data = 42;
	std::cout << "Data = " << myData.data << std::endl;

	// Sérialisation : conversion de l'adresse mémoire de l'objet Data en une valeur entière
	uintptr_t serialized = Serializer::serialize(&myData);
	std::cout << WHITE << "\nSérialisation :" << RESET << \
	 "\nL'adresse de myData est convertie en entier : " << serialized << std::endl;

	// Désérialisation : conversion de la valeur entière précédemment obtenue en adresse mémoire de type Data*
	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << WHITE << "\nDésérialisation :" << RESET << \
	"\nL'entier est reconverti en adresse mémoire de type Data* : " << deserialized << std::endl;

	// Vérification que l'adresse obtenue après désérialisation est la même que l'adresse originale de l'objet Data
	if (deserialized == &myData)
		std::cout << GREEN << "\nSuccès" << RESET << " : La désérialisation a correctement récupéré l'adresse originale de l'objet Data" << std::endl;
	else
		std::cout << RED << "\nÉchec" << RESET << " : L'adresse obtenue après désérialisation ne correspond pas à l'adresse originale" << std::endl;

	return 0;
}