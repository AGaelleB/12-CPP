#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"


/************************* DESTRUCTEUR  *************************/

Base::~Base() {
	// std::cout << RED << "~Base~ destructor called" << RESET << std::endl;
	return;
}


/*************************** FONCTIONS ***************************/

Base* generate() {
	int random = rand() % 3;
	switch (random) {
		case 0:
			std::cout << "Generated an instance of " << WHITE << "class A" << RESET << std::endl;
			return new A();
		case 1:
			std::cout << "Generated an instance of " << WHITE << "class B" << RESET << std::endl;
			return new B();
		case 2:
			std::cout << "Generated an instance of " << WHITE << "class C" << RESET << std::endl;
			return new C();
		default:
			std::cerr << "Error in random generation" << std::endl;
			return NULL;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "Identified object as " << WHITE << "class A" << RESET << std::endl;
	}
	else if (dynamic_cast<B*>(p)) {
		std::cout << "Identified object as " << WHITE << "class B" << RESET << std::endl;
	}
	else if (dynamic_cast<C*>(p)) {
		std::cout << "Identified object as " << WHITE << "class C" << RESET << std::endl;
	}
	else {
		std::cerr << "Unable to identify object" << std::endl;
	}
}


void identify(Base& p) {
	if (typeid(p) == typeid(A)) {
		std::cout << "Identified object as " << WHITE << "class A" << RESET << \
		" with address " << WHITE << &p << RESET << std::endl;
	}
	else if (typeid(p) == typeid(B)) {
		std::cout << "Identified object as " << WHITE << "class B" << RESET << \
		" with address " << WHITE << &p << RESET << std::endl;
	}
	else if (typeid(p) == typeid(C)) {
		std::cout << "Identified object as " << WHITE << "class C" << RESET << \
		" with address " << WHITE << &p << RESET << std::endl;
	}
	else {
		std::cerr << "Unable to identify object" << std::endl;
	}
}