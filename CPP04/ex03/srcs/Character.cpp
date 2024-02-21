#include "../includes/Character.hpp"
#include "../includes/ICharacter.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Character::Character() : _name(""), _nbMateria(0) {
	// std::cout << CYAN << "~Character~ default constructor called" << RESET << std::endl;

	for (int i = 0; i < MaxNbMateria; i++) {
		this->_materia[i] = NULL;
	}

	return;
}

Character::Character(std::string name) : _name(name), _nbMateria(0) {
	// std::cout << CYAN << "~Character~ type constructor called" << RESET << std::endl;

	for (int i = 0; i < MaxNbMateria; i++) {
		this->_materia[i] = NULL;
	}

	return;
}

Character::Character(const Character& rhs) : _name(rhs._name) { // copie profonde 
	// std::cout << CYAN << "~Character~ copy constructor called" << RESET << std::endl;
	
	for (int i = 0; i < MaxNbMateria; i++) {
		this->_materia[i] = rhs._materia[i]->clone();
	}
	*this = rhs;
	return;
}

Character::~Character() {
	// std::cout << RED << "~Character~ destructor called" << RESET << std::endl;

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
	std::cout << CYAN << "~Character~ copy assignment operator called" << RESET << std::endl;

	if (this != &rhs) {

		_name = rhs._name;

		// Je libere la mémoire
		for (int i = 0; i < this->_nbMateria; ++i) {
			delete this->_materia[i];
			this->_materia[i] = NULL;
		}
		_nbMateria = rhs._nbMateria;

		// J'alloue et copie de nvx objets
		for (int i = 0; i < this->_nbMateria; ++i)
			this->_materia[i] = rhs._materia[i]->clone();
	}
	return (*this);
}

/****************************** FONCTIONS MEMBRES ******************************/


std::string const & Character::getName() const {
	return (this->_name);
}


// Cette fonction permet à un personnage d'équiper une materia
void Character::equip(AMateria* m) {

	if (_nbMateria < MaxNbMateria && m != NULL) {
		std::cout << getName() << " has equipped materia \"" << m->getType();
		std::cout << "\" in index : " << _nbMateria << std::endl;

		_materia[_nbMateria++] = m;
	}
	else {
		std::cout << "Failed to equip materia. No more space in inventory or this materia doesn't exist" << std::endl;
		delete m;
	}

}

// Cette fonction permet à un personnage de retirer (mais pas de détruire)
// une materia de son inventaire sans la supprimer
void Character::unequip(int idx) {

	if (idx >= 0 && idx < MaxNbMateria) {
		if (this->_materia[idx] != NULL) {
			std::cout << getName() << " has unequipped materia \"" << this->_materia[idx]->getType();
			std::cout << "\" in index : " << idx << std::endl;
		}
		else {
			std::cout << getName() << " has nothing to unequipped in index : " << idx << std::endl;
		}
	}
	else
		std::cout << "Invalid index: " << idx << std::endl;
}


// Cette fonction permet à un personnage d'utiliser une des matérias équipées sur une cible
void Character::use(int idx, ICharacter& target) {

	if (idx >= 0 && idx < _nbMateria && this->_materia[idx] != NULL) {
		std::cout << getName() << " is using materia \"" << this->_materia[idx]->getType() << "\" on " << target.getName() << std::endl;
		this->_materia[idx]->use(target);
	}

}
