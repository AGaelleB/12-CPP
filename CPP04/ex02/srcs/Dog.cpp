#include "../includes/Dog.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Dog::Dog() : AAnimal("Dog") {
	std::cout << BLUE << "~Dog~ default constructor called" << RESET << std::endl;
	this->_brain = new Brain();
	return;
}

Dog::Dog(const Dog& rhs) : AAnimal("Dog") {
	this->_brain = new Brain(*rhs._brain); // copie profonde du cerveau (Brain)
	std::cout << BLUE << "~Dog~ copy constructor called" << RESET << std::endl;
	return;
}

Dog::~Dog() {
	std::cout << RED << "~Dog~ destructor called" << RESET << std::endl;
	delete _brain;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

Dog& Dog::operator=(const Dog& rhs) {
	std::cout << BLUE << "~Dog~ copy assignment operator called" << RESET << std::endl;

	if (this != &rhs) {
		this->_type = rhs._type;
		delete this->_brain; // Libère la mémoire actuelle de _brain
		this->_brain = new Brain(*rhs._brain); // Allocation d'un nouveau Brain avec copie profonde
	}
	return *this;
}

/****************************** FONCTIONS MEMBRES ******************************/

void	Dog::makeSound() const {
	std::cout << "\"Waouuuf\" 🐶🐕" << std::endl;
	return ;
}

Brain*	Dog::getBrain() const{
	return (this->_brain);
}

void	Dog::setBrain(std::string idea)
{
	this->_brain->setIdea(idea);
	return ;
}