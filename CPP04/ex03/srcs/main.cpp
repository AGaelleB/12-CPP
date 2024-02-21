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

void	mymainGlobal(void) {
	// Création des personnages
	ICharacter* Gaga = new Character("Gaga");
	ICharacter* Bibi = new Character("Bibi");
	ICharacter* Bob = new Character("Bob");


	// Création d'une source de materia pour chaque personnage
	IMateriaSource* srcGaga = new MateriaSource();
	IMateriaSource* srcBibi = new MateriaSource();
	IMateriaSource* srcBob = new MateriaSource();

/**************************************************** GAGA ***************************************************/

	// Apprendre 3 materias à Gaga
	std::cout << BLUE << "\n~~~ Character " << Gaga->getName() << " has been created ~~~" << RESET << std::endl;
	std::cout << GREEN << "-->  Gaga apprend 3 materias." << RESET <<std::endl;
	srcGaga->learnMateria(new Ice());
	srcGaga->learnMateria(new Cure());
	srcGaga->learnMateria(new Ice());

	// Equipement de Gaga avec les 3 materias
	std::cout << GREEN << "\n-->  Gaga s'équipe de ses 3 materias" << RESET << std::endl;
	for (int i = 0; i < 3; i++) {
		Gaga->equip(srcGaga->createMateria("ice"));
	}

	// Retrait de 2 materias équipées de Gaga
	std::cout << GREEN << "\n-->  Gaga retire 2 materias" << RESET << std::endl;
	Gaga->unequip(0);
	Gaga->unequip(1);

	// Equipement de Gaga avec 3 nouvelles materias
	std::cout << GREEN << "\n-->  Gaga s'équipe 3 nouvelles materias" << RESET << std::endl;
	for (int i = 0; i < 3; ++i) {
		Gaga->equip(srcGaga->createMateria("cure"));
	}


/**************************************************** BIBI ****************************************************/
	// Apprendre une materia à Bibi
	std::cout << BLUE << "\n\n\n~~~ Character " << Bibi->getName() << " has been created ~~~" << RESET << std::endl;
	std::cout << GREEN << "-->  Bibi apprend une materia." << RESET << std::endl;
	srcBibi->learnMateria(new Ice());
	Bibi->equip(srcBibi->createMateria("ice"));



/***************************************************** BOB ****************************************************/

	// Tentative d'apprendre 5 materias à Bob
	std::cout << BLUE << "\n\n\n~~~ Character " << Bob->getName() << " has been created ~~~" << RESET << std::endl;
	std::cout << GREEN << "-->  Bob tente d'apprendre 6 materias" << RESET << std::endl;
	for (int i = 0; i < 6; i++) {
		srcBob->learnMateria(new Cure());
	} // ici en cas de mat sup je free mal


	// Retrait de 3 materias équipées de Bob
	std::cout << GREEN << "\n-->  Bob retire 2 materias" << RESET << std::endl;
	Bob->unequip(0);
	Bob->unequip(1);
	// Bob->unequip(12); // erreur


	// Equipement de Bob avec 3 nouvelles materias
	std::cout << GREEN << "\n-->  Bob s'équipe 3 nouvelles materias" << RESET << std::endl;
	for (int i = 0; i < 3; ++i) {
		Bob->equip(srcBob->createMateria("cure"));
	}



	// free
	delete srcGaga;
	delete Gaga;
	delete srcBibi;
	delete Bibi;
	delete srcBob;
	delete Bob;
}

void	mymainGaga(void) {

	// Création des personnages
	ICharacter* Gaga = new Character("Gaga");

	// Création d'une source de materia pour chaque personnage
	IMateriaSource* srcGaga = new MateriaSource();

	// Apprendre 3 materias à Gaga
	std::cout << BLUE << "\n~~~ Character " << Gaga->getName() << " has been created ~~~" << RESET << std::endl;
	std::cout << GREEN << "-->  Gaga apprend 3 materias." << RESET <<std::endl;
	srcGaga->learnMateria(new Ice());
	srcGaga->learnMateria(new Cure());
	// srcGaga->learnMateria(new Ice());

	// Equipement de Gaga avec les 3 materias
	std::cout << GREEN << "\n-->  Gaga s'équipe de ses 3 materias" << RESET << std::endl;
	for (int i = 0; i < 3; i++) {
		Gaga->equip(srcGaga->createMateria("ice"));
	}

	// Retrait de 2 materias équipées de Gaga
	std::cout << GREEN << "\n-->  Gaga retire 2 materias" << RESET << std::endl;
	Gaga->unequip(0);
	Gaga->unequip(1);
	Gaga->unequip(111);

	// Equipement de Gaga avec 3 nouvelles materias
	std::cout << GREEN << "\n-->  Gaga s'équipe 3 nouvelles materias" << RESET << std::endl;
	for (int i = 0; i < 3; ++i) {
		Gaga->equip(srcGaga->createMateria("cure"));
	}

	// free
	delete srcGaga;
	delete Gaga;
}

void	mymainBibi(void) {

	// Création des personnages
	ICharacter* Bibi = new Character("Bibi");

	// Création d'une source de materia pour chaque personnage
	IMateriaSource* srcBibi = new MateriaSource();

	// Apprendre une materia à Bibi
	std::cout << BLUE << "\n\n\n~~~ Character " << Bibi->getName() << " has been created ~~~" << RESET << std::endl;
	std::cout << GREEN << "-->  Bibi apprend une materia." << RESET << std::endl;
	srcBibi->learnMateria(new Ice());
	Bibi->equip(srcBibi->createMateria("ice"));

	// free
	delete srcBibi;
	delete Bibi;
}

void	mymainBob(void) {

	// Création des personnages
	ICharacter* Bob = new Character("Bob");

	// Création d'une source de materia pour chaque personnage
	IMateriaSource* srcBob = new MateriaSource();

	// Tentative d'apprendre 5 materias à Bob
	std::cout << BLUE << "\n\n\n~~~ Character " << Bob->getName() << " has been created ~~~" << RESET << std::endl;
	std::cout << GREEN << "-->  Bob tente d'apprendre 5 materias" << RESET << std::endl;
	srcBob->learnMateria(new Cure());
	srcBob->learnMateria(new Ice());
	srcBob->learnMateria(new Cure());
	srcBob->learnMateria(new Ice());
	srcBob->learnMateria(new Cure());

	// Retrait de 2 materias équipées de Bob
	std::cout << GREEN << "\n-->  Bob retire 3 materias qui ne sont pas encore équipés" << RESET << std::endl;
	Bob->unequip(0);
	Bob->unequip(3);
	Bob->unequip(12);

	std::cout << GREEN << "\n-->  Bob veut s'équiper d'un matereria qui n'existe pas" << RESET << std::endl;
	Bob->equip(srcBob->createMateria("fire"));

	// Equipement de Bob avec 3 nouvelles materias
	std::cout << GREEN << "\n-->  Bob s'équipe 4 nouvelles materias" << RESET << std::endl;
	for (int i = 0; i < 3; ++i) {
		Bob->equip(srcBob->createMateria("cure"));
		Bob->equip(srcBob->createMateria("ice"));
	}

	// Retrait de 2 materias équipées de Bob
	std::cout << GREEN << "\n-->  Bob retire 3 materias" << RESET << std::endl;
	Bob->unequip(0);
	Bob->unequip(3);
	Bob->unequip(12);

	// free
	std::cout << std::endl;
	delete srcBob;
	delete Bob;
}


int main()
{
	// subjectmain();
	// mymainGlobal();

	mymainGaga();
	mymainBibi();
	mymainBob();

	return (0);
}

