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
	const Animal* Copy = new Animal(*theDog); // copy constructor
	std::cout << std::endl;

	// ils executent leurs bruits
	std::cout << "Type : " << theDog->getType() << std::endl;
	std::cout << "Sounds like : ";
	theDog->makeSound();
	std::cout << std::endl;

	std::cout << "Type : " << theCat->getType() << std::endl;
	std::cout << "Sounds like : ";
	theCat->makeSound(); //will output the cat sound!
	std::cout << std::endl;
	
	std::cout << "Type : " << meta->getType() << std::endl;
	std::cout << "Sounds like : ";
	meta->makeSound();
	std::cout << std::endl;

	std::cout << "Copy Type : " << Copy->getType() << std::endl;
	std::cout << std::endl;

	// je free
	delete meta;
	delete theDog;
	delete theCat;
	delete Copy;


	std::cout << "\n\n	~~~ WRONG ANIMAL ~~~\n";

	// je cree mes animaux
	const WrongAnimal* Wrongmeta = new WrongAnimal();
	const WrongAnimal* Wrongcat = new WrongCat();
	const WrongAnimal* WrongCopy = new WrongAnimal(*Wrongcat); // copy constructor
	std::cout << std::endl;

	// ils executent leurs bruits
	std::cout << "Wrong Type : " << Wrongcat->getType() << std::endl;
	std::cout << "Sounds like : ";
	Wrongcat->makeSound(); //will output the cat sound!
	std::cout << std::endl;
	
	std::cout << "Wrong Type : " << Wrongmeta->getType() << std::endl;
	std::cout << "Sounds like : ";
	Wrongmeta->makeSound();
	std::cout << std::endl;

	std::cout << "WrongCopy Type : " << WrongCopy->getType() << std::endl;
	std::cout << std::endl;

	// je free
	delete Wrongmeta;
	delete Wrongcat;
	delete WrongCopy;

	return 0;
}
