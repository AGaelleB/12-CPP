#include "../includes/Character.hpp"
#include "../includes/ICharacter.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Character::Character() : _name(""), _nbMateria(0) {
	std::cout << CYAN << "~Character~ default constructor called" << RESET << std::endl;

	for (int i = 0; i < MaxNbMateria; i++) {
		_materia[i] = NULL;
	}

	return;
}

Character::Character(std::string name) : _name(name), _nbMateria(0) {
	std::cout << CYAN << "~Character~ type constructor called" << RESET << std::endl;

	for (int i = 0; i < MaxNbMateria; i++) {
		_materia[i] = NULL;
	}

	return;
}

Character::Character(const Character& rhs) : _name(rhs._name) { // copie profonde 
	std::cout << CYAN << "~Character~ copy constructor called" << RESET << std::endl;
	
	for (int i = 0; i < MaxNbMateria; i++) {
		_materia[i] = rhs._materia[i]->clone();
	}
	*this = rhs;
	return;
}

Character::~Character() {
	std::cout << RED << "~Character~ destructor called" << RESET << std::endl;

	for (int i = 0; i < _nbMateria; i++) {
		if (_materia[i])
			delete _materia[i];
	}

	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

Character& Character::operator=(const Character& rhs) {
	std::cout << CYAN << "~Character~ copy assignment operator called" << RESET << std::endl;

	if (this != &rhs) {

		_name = rhs._name;

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


std::string const & Character::getName() const {
	return (this->_name);
}


// Cette fonction permet à un personnage d'équiper une materia
void Character::equip(AMateria* m) {

	if (_nbMateria < 4 && m != NULL) {
		std::cout << getName() << " has equipped materia : " << m->getType() << std::endl;
		_materia[_nbMateria++] = m;
	}

}


// Cette fonction permet à un personnage de retirer (mais pas de détruire)
// une materia de son inventaire sans la supprimer
void Character::unequip(int idx) {

	if (idx >= 0 && idx < MaxNbMateria && _materia[idx] != NULL) {
		std::cout << getName() << " has unequipped materia : " << _materia[idx]->getType() << std::endl;
		_materia[idx] = NULL;
	}
}


// Cette fonction permet à un personnage d'utiliser une des matérias équipées sur une cible
void Character::use(int idx, ICharacter& target) {

	if (idx >= 0 && idx < _nbMateria && _materia[idx] != NULL) {
		std::cout << getName() << " is using materia \"" << _materia[idx]->getType() << "\" on " << target.getName() << std::endl;
		_materia[idx]->use(target);
	}

}
