#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Brain.hpp"


int main() {


	std::cout << "	~~~ ANIMAL ~~~\n";

	// je cree mes animaux qui heritent de AAnimal
	const AAnimal* theDog = new Dog();
	const AAnimal* theCat = new Cat();

	// ils executent leurs bruits
	std::cout << "\nType : " << theDog->getType() << std::endl;
	std::cout << "Sounds like : ";
	theDog->makeSound();
	std::cout << std::endl;

	std::cout << "Type : " << theCat->getType() << std::endl;
	std::cout << "Sounds like : ";
	theCat->makeSound(); //will output the cat sound!
	std::cout << std::endl;


	// je free
	delete theDog;
	delete theCat;


	// std::cout << "	~~~ CLASSE ABSTRAITE NE PEUT ETRE INSTANCIEE ~~~\n";

	// // Ne fonctionnera pas car AAnimal est abstrait 
	// const AAnimal* meta = new AAnimal();

	// std::cout << "Type : " << meta->getType() << std::endl;
	// std::cout << "Sounds like : ";
	// meta->makeSound();
	// std::cout << std::endl;

	// delete meta;


	return (0);
}

