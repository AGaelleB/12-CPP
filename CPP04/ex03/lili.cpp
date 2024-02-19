int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);


	delete bob;
	delete me;
	delete src;
}


void MateriaSource::learnMateria(AMateria* m) {
	
	if (_nbMateria == MaxNbMateria)
		std::cout << "MateriaSource can't learn more than" << MaxNbMateria << "materia" << std::endl;


	else if (_nbMateria < MaxNbMateria && m != NULL) {
		for (int i = 0; i < _nbMateria; ++i) {
			if (_materia[i] == m) {
				std::cout << "MateriaSource " <<  m->getType() << "is already learned" << std::endl;
				return;
			}
		}
		_materia[_nbMateria++] = m;
		std::cout << "MateriaSource learned new materia : " << m->getType() << std::endl;

	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < _nbMateria; ++i) {
		if (_materia[i] && _materia[i]->getType() == type) {
			std::cout << "MateriaSource created new materia : " << type << std::endl;
			return (_materia[i]->clone());
		}
	}
	return (NULL);
}

➜  ex03 git:(main) ✗ ./Materia
~MateriaSource~ default constructor called
~Abstract Materia~ default constructor called
~Ice~ default constructor called
MateriaSource learned new materia : NULL
~Abstract Materia~ default constructor called
~Cure~ default constructor called
MateriaSource learned new materia : NULL
~Character~ type constructor called
~Character~ type constructor called
~Character~ destructor called
~Character~ destructor called
~MateriaSource~ destructor called
~Ice~ destructor called
~Abstract Materia~ destructor called
~Cure~ destructor called
~Abstract Materia~ destructor called