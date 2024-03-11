#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"

int main() {

	std::cout << "	~~~ ANIMAL ~~~\n";
	
	// je cree mes animaux
	const Animal* meta = new Animal();
	const Animal* theDog = new Dog();
	const Animal* theCat = new Cat();
	const Animal* Copy = new Animal(*theDog);
	std::cout << std::endl;

	// ils executent leurs bruits
	std::cout << "Type : " << theDog->getType() << std::endl;
	std::cout << "Sounds like : ";
	theDog->makeSound();
	std::cout << std::endl;

	std::cout << "Type : " << theCat->getType() << std::endl;
	std::cout << "Sounds like : ";
	theCat->makeSound();
	std::cout << std::endl;
	
	std::cout << "Type : " << meta->getType() << std::endl;
	std::cout << "Sounds like : ";
	meta->makeSound();
	std::cout << std::endl;

	std::cout << "Copy Type : " << Copy->getType() << std::endl;
	std::cout << std::endl;

	// je delete
	delete meta;
	delete theDog;
	delete theCat;
	delete Copy;


	std::cout << "\n\n	~~~ WRONG ANIMAL ~~~\n";

	// je cree mes animaux
	const WrongAnimal*	WrongMeta = new WrongAnimal();
	const WrongAnimal*	WrongCatAnimal = new WrongCat();
	const WrongCat		WrongCatSound; // const par default donc pas a free
	
	std::cout << std::endl;

	// ils executent leurs bruits
	std::cout << "Wrong Type : " << WrongMeta->getType() << std::endl;
	std::cout << "Sounds like : ";
	WrongMeta->makeSound();
	std::cout << std::endl;
	
	std::cout << "Wrong Type : " << WrongCatAnimal->getType() << std::endl;
	std::cout << "Sounds like : ";
	WrongCatAnimal->makeSound();
	std::cout << std::endl;
	
	std::cout << "Wrong Type : " << WrongCatSound.getType() << std::endl;
	std::cout << "Sounds like : ";
	WrongCatSound.makeSound();
	std::cout << std::endl;

	// je delete
	delete WrongMeta;
	delete WrongCatAnimal;

	return 0;
}
