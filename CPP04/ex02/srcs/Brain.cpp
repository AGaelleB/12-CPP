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
	if (index >= 0 && index < 100) {
		return this->_ideas[index];
	}
	else
		return "Index invalide";
}

void Brain::setIdea(const std::string& idea) {
	for (int i = 0; i < 100; i++) {
		if (this->_ideas[i].empty()) {
			this->_ideas[i] = idea;
			return;
		}
	}
	std::cout << "Le cerveau est plein, impossible d'ajouter plus d'idées" << std::endl;
}
