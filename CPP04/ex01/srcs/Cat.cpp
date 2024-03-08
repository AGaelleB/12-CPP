#include "../includes/Cat.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Cat::Cat() : Animal("Cat") {
	std::cout << BLUE << "~Cat~ default constructor called" << RESET << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain(); // creation du brain
	return;
}

Cat::Cat(std::string type) : Animal("Cat") {
	std::cout << BLUE << "~Cat~ type constructor called" << RESET << std::endl;
	this->_type = type;
	this->_brain = new Brain(); // creation du brain
	return;
}

Cat::Cat(const Cat& rhs) : Animal(rhs._type) {
	this->_brain = new Brain(*rhs._brain); // copie profonde du cerveau (Brain)
	std::cout << BLUE << "~Cat~ copy constructor called" << RESET << std::endl;
	return;
}

Cat::~Cat() {
	std::cout << RED << "~Cat~ destructor called" << RESET << std::endl;
	delete _brain;
	return;
}



/*************************** OPERATEUR D'AFFECTATION  **************************/

Cat& Cat::operator=(const Cat& rhs) { 
	std::cout << BLUE << "~Cat~ copy assignment operator called" << RESET << std::endl;

	if (this != &rhs) { // Protection contre l'auto-affectation
		this->_type = rhs._type;
		delete this->_brain; // Libère la mémoire actuelle de _brain
		this->_brain = new Brain(*rhs._brain); // Allocation d'un nouveau Brain avec copie profonde
	}
	
	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

void	Cat::makeSound() const{
	std::cout << "\"Miaouuu\" 🐱🐈" << std::endl;
	return ;
}

Brain*	Cat::getBrain() const{
	return (this->_brain);
}

void	Cat::setBrain(std::string idea)
{
	this->_brain->setIdea(idea);
	return ;
}