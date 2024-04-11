#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include "../includes/main.hpp"


int main() {

	std::srand(std::time(0));


	std::cout << BLUE << "\n-> Generated 5 pointers" << RESET << std::endl;
	for (int i = 0; i < 5; i++)
	{
		Base* objPtr = generate();
		identify(objPtr);
		std::cout << std::endl;

		delete objPtr;
	}

	std::cout << BLUE << "-> Generated 5 references" << RESET << std::endl;
	for (int i = 0; i < 5; i++)
	{
		Base* objPtr = generate();
		Base& objRef = *objPtr;		// je stock mon ptr dans la ref pour le free a la fin
		identify(objRef);
		std::cout << std::endl;

		delete objPtr;
	}

	return 0;
}
