#include "../includes/Brain.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Brain::Brain() {
	std::cout << BLUE << "~Brain~ default constructor called" << RESET << std::endl;
	return;
}

Brain::Brain(const Brain& rhs) {
	std::cout << BLUE << "~Brain~ copy constructor called" << RESET << std::endl;
	*this = rhs;
	return;
}

Brain::~Brain() {
	std::cout << RED << "~Brain~ destructor called" << RESET << std::endl;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

Brain& Brain::operator=(const Brain& rhs) {
	std::cout << BLUE << "~Brain~ copy assignment operator called" << RESET << std::endl;

	for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	return (*this);
}

/****************************** FONCTIONS MEMBRES ******************************/

std::string Brain::getIdea(int index) const {
	return (this->_ideas[index]);
}

void Brain::setIdea(int index, const std::string idea) {
	this->_ideas[index] = idea;
}
