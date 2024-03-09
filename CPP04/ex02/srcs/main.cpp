#include "../includes/AAnimal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Brain.hpp"


// void testAbstractClassInstanciate() {

// 	std::cout << "	~~~ CLASSE ABSTRAITE NE PEUT ETRE INSTANCIEE ~~~\n";

// 	// Ne fonctionnera pas car AAnimal est abstrait 
// 	AAnimal* test = new AAnimal();

// 	std::cout << "Type : " << test->getType() << std::endl;
// 	std::cout << "Sounds like : ";
// 	test->makeSound();
// 	std::cout << std::endl;

// 	delete test;
// }

void testCopyProfonde() {

	std::cout << "\n\n	~~~ Test copie profonde 2 ~~~\n" << std::endl;

	Dog basic;
	{
		Dog tmp = basic;
		std::cout << "Temporary Dog object created as a copy of basic.\n";
	}

	std::cout << "\nAfter the temporary Dog object is destroyed, the basic Dog object remains intact.\n";
}

int main() {

	// testAbstractClassInstanciate();

	const int	numAnimals = 7;
	AAnimal*		animals[numAnimals];


	std::cout << "\nJe vais créer " << numAnimals << " animaux, la moitié sera composée d’objets Dog et l’autre moitié d’objets Cat\n" << std::endl;

	// Création des chiens
	int numDogCreated = 0;
	for (int i = 0; i < (numAnimals / 2); i++) {
		animals[i] = new Dog();
		std::cout << "Chien #" << i + 1 << "/" << numAnimals / 2 << " créé" << std::endl;
		numDogCreated++;
	}

	// Création des chats
	for (int i = numDogCreated; i < numAnimals; ++i) {
		animals[i] = new Cat();
		std::cout << "Chat #" << (i - numDogCreated) + 1 << "/" << (numAnimals - numDogCreated) << " créé" << std::endl;
	}

	/**************************************************************************************************************/
	std::cout << "\n\n	~~~ Test des cerveaux des chiens avec une copie profonde ~~~\n" << std::endl;
	Dog* dog[2];

	dog[0] = new Dog();
	if (dog[0]) {
		Brain* test1 = dog[0]->getBrain(); // attribution du cerveau
		if (test1) {
			for (int i = 0; i < 102; i++) {
				test1->setIdea("I have a idea waouf !");
				std::cout << "Idea #" << i+1 << ": " << test1->getIdea(i) << std::endl;
			}
		}
	}

	dog[1] = new Dog(*dog[0]); // copie du 1er chien
	// Vérification et affichage de l'idée dans le cerveau du chien copié.
	if (dog[1]) {
		Brain* test2 = dog[1]->getBrain();
		if (test2) {
			std::cout << "\nIdée dans le cerveau du chien copié : " << test2->getIdea(0) << std::endl;
		}
	}

	// testCopyProfonde();

	/**************************************************************************************************************/
	std::cout << "\n	~~~ Suppression des animaux tests pour les copies profondes~~~\n" << std::endl;
	delete dog[1];
	std::cout << "Dog[0] a été supprimé" << std::endl;
	delete dog[0];
	std::cout << "Dog[1], copie de Dog[0] a été supprimé" << std::endl;

	std::cout << "\n	~~~ Suppression des animaux ~~~\n" << std::endl;
	for (int i = 0; i < numAnimals; i++) {
		delete animals[i];
		std::cout << "Animal #" << i+1 << " a été supprimé" << std::endl;

	}

	std::cout << "\nLes " << numAnimals << " animaux ont été supprimés" << std::endl;

	return 0;
}
