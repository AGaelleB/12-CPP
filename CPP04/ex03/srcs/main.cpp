#include "../includes/Character.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include "../includes/AMateria.hpp"
#include "../includes/MateriaSource.hpp"
#include "../includes/IMateriaSource.hpp"


void	subjectmain(void) {

	std::cout << BLUE << "\n-----------------------------------------------------------------" << RESET << std::endl;
	std::cout << BLUE << "|			Subject main				|" << RESET << std::endl;
	std::cout << BLUE << "-----------------------------------------------------------------\n" << RESET << std::endl;

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
	std::cout << std::endl;

}

void	mymainGaga(void) {

	ICharacter*	Gaga = new Character("Gaga");
	ICharacter*	Target = new Character("Target");
	IMateriaSource* srcGaga = new MateriaSource(); // source de materia pour Gaga

	std::cout << BLUE << "\n-----------------------------------------------------------------" << RESET << std::endl;
	std::cout << BLUE << "|		Character " << Gaga->getName() << " has been created			|" << RESET << std::endl;
	std::cout << BLUE << "-----------------------------------------------------------------\n" << RESET << std::endl;

	std::cout << CYAN << "\n-->  Gaga essaie d'apprendre 5 materias" << RESET <<std::endl;
	srcGaga->learnMateria(new Cure());
	srcGaga->learnMateria(new Ice());
	srcGaga->learnMateria(new Cure());
	srcGaga->learnMateria(new Ice());
	srcGaga->learnMateria(new Cure());

	std::cout << CYAN << "\n-->  Gaga retire 3 materias qui ne sont pas encore équipés" << RESET << std::endl;
	Gaga->unequip(0);
	Gaga->unequip(3);
	Gaga->unequip(12);

	std::cout << CYAN << "\n-->  Gaga veut s'équiper d'un matereria qui n'existe pas" << RESET << std::endl;
	Gaga->equip(srcGaga->createMateria("fire"));

	std::cout << CYAN << "\n-->  Gaga essaie de s'équiper de 5 materias" << RESET << std::endl;
	Gaga->equip(srcGaga->createMateria("ice"));
	Gaga->equip(srcGaga->createMateria("cure"));
	Gaga->equip(srcGaga->createMateria("ice"));
	Gaga->equip(srcGaga->createMateria("cure"));
	Gaga->equip(srcGaga->createMateria("ice")); // pas de place pour ce materia

	std::cout << CYAN << "\n-->  Gaga utilise ses materias" << RESET << std::endl;
	Gaga->use(0, *Target);
	Gaga->use(1, *Target);
	Gaga->use(2, *Target);
	Gaga->use(3, *Target);
	Gaga->use(4, *Target); // ne s'affiche pas car existe pas

	std::cout << CYAN << "\n-->  Gaga retire 2 materias + 1 materia invalid" << RESET << std::endl;
	Gaga->unequip(0);
	Gaga->unequip(3);
	Gaga->unequip(42);

	std::cout << CYAN << "\n-->  Gaga s'équipe d'1 nouvelle materia" << RESET << std::endl;
	Gaga->equip(srcGaga->createMateria("cure"));
	Gaga->equip(srcGaga->createMateria("ice"));
	Gaga->equip(srcGaga->createMateria("cure")); // ne pourra pas s equiper car plus de place

	std::cout << CYAN << "\n-->  ... Delete ..." << RESET << std::endl;
	delete srcGaga;
	delete Gaga;
	delete Target;
	std::cout << std::endl;
}

int main()
{
	// subjectmain();
	mymainGaga();
	return (0);
}
