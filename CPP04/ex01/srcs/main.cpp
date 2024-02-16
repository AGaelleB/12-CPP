#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Brain.hpp"


int main() {

	const int numAnimals = 7; // Nombre total d'animaux dans le tableau
	Animal* animals[numAnimals]; // Tableau d'animaux

	std::cout << "\nJe vais créer " << numAnimals << " animaux, la moitié sera composée d’objets Dog et l’autre moitié d’objets Cat." << std::endl;


	int	numDogCreated = 0;
	// Création des chiens
	std::cout << "\n   ~~~ Création des chiens ~~~\n" << std::endl;
	for (int i = 0; i < (numAnimals/2) ; i++) {
		animals[i] = new Dog();
		std::cout << "Chien n." << i + 1 << "/" << numAnimals/2 << " créé." << std::endl;
		numDogCreated++;
	}

	// Création des chats
	std::cout << "\n\n   ~~~ Création des chats ~~~\n" << std::endl;
	for (int i = numDogCreated; i < numAnimals; ++i) {
		animals[i] = new Cat();
		std::cout << "Chat n." << (i - numDogCreated) + 1 << "/" << numAnimals - numDogCreated << " créé." << std::endl;
	}

	// Suppression des animaux
	std::cout << "\n   ~~~ Suppression des animaux ~~~\n" << std::endl;
	for (int i = 0; i < numAnimals; i++) {
		delete animals[i];
	}

	std::cout << "\nLes " << numAnimals << " animaux ont été supprimés" << std::endl;


	return 0;
}

