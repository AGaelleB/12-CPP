#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"
#include "../includes/main.hpp"


int main() {

	Data myData;
	myData.data = 42;
	std::cout << "Data = " << myData.data << std::endl;

	uintptr_t ptr = Serializer::serialize(&myData);
	std::cout << WHITE << "\nSérialisation :" << RESET << \
	 "\nL'adresse de myData est convertie en entier : " << ptr << std::endl;

	Data* raw = Serializer::deserialize(ptr);
	std::cout << WHITE << "\nDésérialisation :" << RESET << \
	"\nL'entier est reconverti en adresse mémoire de type Data* : " << raw << std::endl;

	if (raw == &myData)
		std::cout << GREEN << "\nSuccès" << RESET << " : La désérialisation a correctement récupéré l'adresse d'origine de l'objet Data" << std::endl;
	else
		std::cout << RED << "\nÉchec" << RESET << " : L'adresse obtenue après désérialisation ne correspond pas à l'adresse d'origine" << std::endl;

	return 0;
}