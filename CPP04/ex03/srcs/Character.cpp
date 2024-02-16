#include "../includes/Character.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Character::Character() : _name(""), _nbItems(0) {
	std::cout << CYAN << "~Character~ default constructor called" << RESET << std::endl;

	for (int i = 0; i < MaxNbItems; i++) {
		_items[i] = NULL;
	}

	return;
}

Character::Character(std::string name) : _name(name), _nbItems(0) {
	std::cout << CYAN << "~Character~ type constructor called" << RESET << std::endl;
	
	for (int i = 0; i < MaxNbItems; i++) {
		_items[i] = NULL;
	}

	return;
}

Character::Character(const Character& rhs) { // faire une copie profonde 
	*this = rhs;
	std::cout << CYAN << "~Character~ copy constructor called" << RESET << std::endl;
	return;
}

Character::~Character() {
	std::cout << RED << "~Character~ destructor called" << RESET << std::endl;

	for (int i = 0; i < _nbItems; i++) {
		delete _items[i];
	}

	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

Character& Character::operator=(const Character& rhs) {
	if (this != &rhs) {

		_name = rhs._name;

		// Je libere la mémoire
		for (int i = 0; i < _nbItems; ++i)
			delete _items[i];
		_nbItems = rhs._nbItems;

		// J'alloue et copie de nvx objets
		for (int i = 0; i < _nbItems; ++i)
			_items[i] = rhs._items[i]->clone();
	}
	return (*this);
}

/****************************** FONCTIONS MEMBRES ******************************/


std::string const & Character::getName() const {
	return (this->_name);
}


// Cette fonction permet à un personnage d'équiper une materia
void Character::equip(AMateria* m) {

	if (_nbItems < 4 && m != NULL)
		_items[_nbItems++] = m;

}


// Cette fonction permet à un personnage de retirer (mais pas de détruire)
// une materia de son inventaire sans la supprimer
void Character::unequip(int idx) {

	if (idx >= 0 && idx < MaxNbItems && _items[idx] != NULL)
		_items[idx] = NULL;
		// retirer sans supprimer pour éviter les leaks
}


// Cette fonction permet à un personnage d'utiliser une des matérias équipées sur une cible
void Character::use(int idx, ICharacter& target) {

	if (idx >= 0 && idx < _nbItems && _items[idx] != NULL)
		_items[idx]->use(target);

}