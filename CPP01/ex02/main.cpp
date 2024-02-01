#include <iostream>

/*  POINTEURS ET REFERENCES
	pointeur : "*"
		=> si a un moment ca ne doit pas exister (NULL) ou changer,
		il faut utiliser un pointeur

	reference : "&"
		- Une ref ne peut pas pointer sur NULL.
		- C'est comme un pointeur dereferencé.
		- La ref pointe sur une variable et on ne peut pas changer vers 
		quoi elle pointe.
		=> si ca doit tjrs exister et jamais changer
		j'utiliser une reference
 */

int main() {

	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;


	std::cout << "L’adresse de la string en mémoire est : " << &string << std::endl;
	std::cout << "L’adresse stockée dans stringPTR est : " << stringPTR << std::endl;
	std::cout << "L’adresse stockée dans stringREF est : " << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << "La valeur de la string est : " << string << std::endl;
	std::cout << "La valeur pointée par stringPTR est : " <<  *stringPTR << std::endl;
	std::cout << "La valeur pointée par stringREF est : " << stringREF << std::endl;


	return 0;
}
