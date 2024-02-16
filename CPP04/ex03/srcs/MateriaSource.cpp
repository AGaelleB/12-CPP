#include "../includes/MateriaSource.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

MateriaSource::MateriaSource() : _nbMateria(0) {
	std::cout << CYAN << "~MateriaSource~ default constructor called" << RESET << std::endl;

	for (int i = 0; i < MaxNbMateria; i++) {
		_materia[i] = NULL;
	}

	return;
}

MateriaSource::MateriaSource(const MateriaSource& rhs) {
	std::cout << CYAN << "~MateriaSource~ copy constructor called" << RESET << std::endl;
	*this = rhs;
}

MateriaSource::~MateriaSource() {
	std::cout << RED << "~MateriaSource~ destructor called" << RESET << std::endl;

	for (int i = 0; i < _nbMateria; i++) {
		delete _materia[i];
	}

	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
	std::cout << CYAN << "~MateriaSource~ copy assignment operator called" << RESET << std::endl;

	if (this != &rhs) {

		// Je libere la mémoire
		for (int i = 0; i < _nbMateria; ++i)
			delete _materia[i];
		_nbMateria = rhs._nbMateria;

		// Je repasse mes ptr a NULL
		for (int i = 0; i < MaxNbMateria; i++)
			_materia[i] = NULL;

		// J'alloue et copie de nvx objets
		for (int i = 0; i < _nbMateria; ++i)
			_materia[i] = rhs._materia[i]->clone();
	}
	return (*this);
}

/****************************** FONCTIONS MEMBRES ******************************/


void MateriaSource::learnMateria(AMateria* m) {
	if (_nbMateria < MaxNbMateria && m != nullptr) {
		for (int i = 0; i < _nbMateria; ++i) {
			if (_materia[i] == m) // Vérifie si la materia est déjà apprise
				return;
		}
		_materia[_nbMateria++] = m;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < _nbMateria; ++i) {
		if (_materia[i] && _materia[i]->getType() == type) {
			return _materia[i]->clone();
		}
	}
	return nullptr;
}