#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Serializer::Serializer() {
	// std::cout << CYAN << "~Serializer~ default constructor called" << RESET << std::endl;

	return;
}


Serializer::Serializer(const Serializer& rhs) {
	// std::cout << CYAN << "~Serializer~ copy constructor called" << RESET << std::endl;
	(void)rhs;
	return;
}

Serializer::~Serializer() {
	// std::cout << RED << "~Serializer~ destructor called" << RESET << std::endl;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

Serializer& Serializer::operator=(const Serializer& rhs) {
	// std::cout << CYAN << "~Serializer~ copy assignment operator called" << RESET << std::endl;
	(void)rhs;
	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}


/* 
	** static cast **
	cast d'une valeure "b" vers un "int" s ecrit : 
	int a = 42;
	double b = a;
	int d = static_cast<int>(b); // ici je cast donc un double en un int
	Le static_cast est vérifié lors de la compilation et peut entraîner une perte de données si la conversion n'est pas sûre.


	** Reinterpret cast **
	utile pour le retypage par exemple d'un void vers un char
 */