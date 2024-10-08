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
	** Reinterpret cast **
	utile pour le retypage par exemple d'un void vers un char
 */