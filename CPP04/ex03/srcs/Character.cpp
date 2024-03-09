#include "../includes/Character.hpp"
#include "../includes/ICharacter.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Character::Character() : _name(""), _nbMateria(0) {
	std::cout << "~Character~ default constructor called" << std::endl;

	for (int i = 0; i < MaxNbMateria; i++) {
		this->_materia[i] = NULL;
	}

	return;
}

Character::Character(std::string name) : _name(name), _nbMateria(0) {
	std::cout << "~Character~ type constructor called" << std::endl;

	for (int i = 0; i < MaxNbMateria; i++) {
		this->_materia[i] = NULL;
	}

	return;
}

Character::Character(const Character& rhs) : _name(rhs._name) {
	std::cout << "~Character~ copy constructor called" << std::endl;
	
	// je clone chaque materia indépendamment en utilisant clone() pour réaliser une copie profonde
	for (int i = 0; i < MaxNbMateria; i++) {
		this->_materia[i] = rhs._materia[i]->clone();
	}
	return;
}

Character::~Character() {
	std::cout << RED << "~Character~ destructor called" << RESET << std::endl;

	for (int i = 0; i < this->_nbMateria; i++) {
		if (_materia[i]) {
			delete this->_materia[i];
			this->_materia[i] = NULL;
		}
	}

	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

Character& Character::operator=(const Character& rhs) {
	std::cout << "~Character~ copy assignment operator called" << std::endl;

	if (this != &rhs) {

		_name = rhs._name;

		// Je libere la mémoire
		for (int i = 0; i < this->_nbMateria; i++) {
			delete this->_materia[i];
			this->_materia[i] = NULL;
		}
		_nbMateria = rhs._nbMateria;

		// J'alloue et copie de nvx objets
		for (int i = 0; i < this->_nbMateria; i++)
			this->_materia[i] = rhs._materia[i]->clone();
	}
	return (*this);
}

/****************************** FONCTIONS MEMBRES ******************************/

std::string const & Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << BOLD_WHITE << "Failed to equip materia. No materia provided" << RESET << std::endl;
		return;
	}

	if (_nbMateria >= MaxNbMateria) {
		std::cout << BOLD_WHITE << "Failed to equip materia. No more space in inventory" << RESET << std::endl;
		delete m;
		return;
	}

	for (int i = 0; i < MaxNbMateria; i++) {
		if (!_materia[i]) {
			_materia[i] = m;
			std::cout << BOLD_WHITE << getName() << " has equipped materia \"" << m->getType();
			std::cout << "\" in index : " << i << RESET << std::endl;
			_nbMateria++;
			return;
		}
	}

	std::cout << BOLD_WHITE << "Failed to equip materia. No more space in inventory" << RESET << std::endl;
	delete m;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= MaxNbMateria) {
		std::cout << BOLD_WHITE << "Invalid index: " << idx << RESET << std::endl;
		return;
	}

	if (!_materia[idx]) {
		std::cout << BOLD_WHITE << getName() << " has nothing to unequipped in index : " << idx << RESET << std::endl;
		return;
	}

	std::cout << BOLD_WHITE << getName() << " has unequipped materia \"" << _materia[idx]->getType();
	std::cout << "\" in index : " << idx << RESET << std::endl;

	delete _materia[idx];
	_materia[idx] = NULL; // Marque l'emplacement comme disponible
	_nbMateria--; // Décrémente le nombre de matérias équipées
}

void Character::use(int idx, ICharacter& target) {

	if (idx >= 0 && idx < _nbMateria && this->_materia[idx] != NULL) {
		this->_materia[idx]->use(target);
	}
}

