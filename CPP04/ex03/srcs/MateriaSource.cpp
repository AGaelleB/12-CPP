#include "../includes/MateriaSource.hpp"
#include "../includes/IMateriaSource.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

MateriaSource::MateriaSource() : _nbMateria(0) {
	std::cout << "~MateriaSource~ default constructor called" << std::endl;

	for (int i = 0; i < MaxNbMateria; i++) {
		this->_materia[i] = NULL;
	}

	return;
}

MateriaSource::MateriaSource(const MateriaSource& rhs) { 
	std::cout << "~MateriaSource~ copy constructor called" << std::endl;

	for (int i = 0; i < MaxNbMateria; i++) {
		this->_materia[i] = rhs._materia[i]->clone();
	}
	return;

}

MateriaSource::~MateriaSource() {
	std::cout << RED << "~MateriaSource~ destructor called" << RESET << std::endl;

	for (int i = 0; i < this->_nbMateria; i++) {
		delete this->_materia[i];
		this->_materia[i] = NULL;
	}

	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
	std::cout << "~MateriaSource~ copy assignment operator called" << std::endl;

	if (this != &rhs) {

		// Je libere la mémoire
		for (int i = 0; i < this->_nbMateria; i++) {
			delete this->_materia[i];
			this->_materia[i] = NULL;
		}
		this->_nbMateria = rhs._nbMateria;

		// J'alloue et copie de nvx objets
		for (int i = 0; i < _nbMateria; i++)
			this->_materia[i] = rhs._materia[i]->clone();
	}
	return (*this);
}

/****************************** FONCTIONS MEMBRES ******************************/


void MateriaSource::learnMateria(AMateria* m) {
	
	if (this->_nbMateria == MaxNbMateria) {
		std::cout << BOLD_WHITE << "MateriaSource can't learn more than " << MaxNbMateria << " materias" << RESET << std::endl;
		delete m;
	}

	else if (this->_nbMateria < MaxNbMateria && m != NULL) {
		for (int i = 0; i < this->_nbMateria; i++) {
			if (this->_materia[i] == m) {
				std::cout << BOLD_WHITE << "MateriaSource " <<  m->getType() << "is already learned" << RESET << std::endl;
				return;
			}
		}
		this->_materia[this->_nbMateria++] = m;
		std::cout << BOLD_WHITE << "MateriaSource learned materia \"" << m->getType() << "\"" << RESET << std::endl;
	}
}


AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < this->_nbMateria; i++) {
		if (this->_materia[i] && this->_materia[i]->getType() == type) {
			std::cout << BOLD_WHITE << "MateriaSource created materia \"" << type << "\"" << RESET << std::endl;
			return (this->_materia[i]->clone());
		}
	}
	return (NULL);
}