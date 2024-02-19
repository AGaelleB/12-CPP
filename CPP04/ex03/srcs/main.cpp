#include "../includes/Character.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Materia.hpp"
#include "../includes/MateriaSource.hpp"
#include "../includes/IMateriaSource.hpp"


void	subjectmain(void) {
	
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

	std::cout << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;

	delete bob;
	delete me;
	delete src;
}


void	mymain(void) {

	// Création des personnages
	Character Gaga("Gaga");
	Character Bibi("Bibi");
	Character Bob("Bob");

	// Création d'une source de materia
	IMateriaSource* src = new MateriaSource();

	// Apprendre 3 materias à Gaga
	std::cout << "Gaga apprend trois materias." << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());

	// Equipement de Gaga avec les 3 materias
	std::cout << "Gaga équipe ses trois materias." << std::endl;
	for (int i = 0; i < 3; ++i) {
		Gaga.equip(src->createMateria("ice"));
	}

	// Retrait de deux materias équipées de Gaga
	std::cout << "Gaga retire deux materias." << std::endl;
	Gaga.unequip(0);
	Gaga.unequip(1);

	// Equipement de Gaga avec trois nouvelles materias
	std::cout << "Gaga équipe trois nouvelles materias." << std::endl;
	for (int i = 0; i < 3; ++i) {
		Gaga.equip(src->createMateria("cure"));
	}

	// Apprendre une materia à Bibi
	std::cout << "Bibi apprend une materia." << std::endl;
	src->learnMateria(new Ice());
	Bibi.equip(src->createMateria("ice"));

	// Tentative d'apprendre 5 materias à Bob
	std::cout << "Bob tente d'apprendre cinq materias." << std::endl;
	for (int i = 0; i < 5; ++i) {
		src->learnMateria(new Cure());
	}

	// Nettoyage de la mémoire
	delete src;
}

int main()
{
	// subjectmain();
	mymain();

	return (0);
}
