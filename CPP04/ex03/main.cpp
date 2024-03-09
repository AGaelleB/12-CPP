/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:06:33 by rertzer           #+#    #+#             */
/*   Updated: 2024/03/09 14:45:11 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define RESET	"\033[0m"


// int main()
// {

// 	AMateria * tmp;
// 	AMateria *	garbage;

// 	std::cout << "Materia source\n";
// 	IMateriaSource* src = new MateriaSource();
// 	std::cout << std::endl;
// 	src->learnMateria(new Ice());
// 	std::cout << std::endl;
// 	src->learnMateria(new Cure());
// 	std::cout << std::endl;
// 	src->learnMateria(new Ice());
// 	std::cout << std::endl;
// 	src->learnMateria(new Ice());
// 	std::cout << std::endl;
// 	src->learnMateria(new Cure());
// 	std::cout << std::endl;
// 	src->learnMateria(new Ice());

// 	std::cout << std::endl;
// 	MateriaSource*	src2 = new MateriaSource();
// 	src2->learnMateria(new Ice());
// 	std::cout << std::endl;
// 	MateriaSource*	src3 = src2;

// 	std::cout << "\nCharacter\n";
// 	ICharacter* me = new Character("me");
// 	std::cout << std::endl;
// 	ICharacter* bob = new Character("bob");
// 	std::cout << std::endl;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	garbage = src->createMateria("cure");
// 	me->equip(garbage);

// 	tmp = src3->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src3->createMateria("cure");

	
// 	std::cout << "\nusing staff.\n";	
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	me->unequip(1);
// 	me->use(1, *bob);
// 	me->use(2, *me);
// 	me->use(5, *bob);
// 	me->use(-42, *bob);

// 	std::cout << "\nFilling Bob's backpack\n";
// 	tmp = src->createMateria("ice");
// 	bob->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	bob->equip(tmp);
// 	tmp = src->createMateria("ice");
// 	bob->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	bob->equip(tmp);
// 	tmp = src->createMateria("ice");
// 	bob->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	bob->equip(tmp);

// 	std::cout << std::endl;
// 	for (int i = -2; i < 6; i++)
// 		bob->use(i, *me);

// 	std::cout << std::endl;

// 	std::cout << "\nDeleting...\n";
// 	delete bob;
// 	std::cout << std::endl;
// 	delete me;
// 	std::cout << std::endl;
// 	delete src;
// 	std::cout << std::endl;
// 	delete src2;
// 	std::cout << std::endl;
// 	delete garbage;
// 	return 0;
// }

void	mymainGaga(void) {

	ICharacter*	Gaga = new Character("Gaga");
	ICharacter*	Target = new Character("Target");

	std::cout << BLUE << "\n-----------------------------------------------------------------" << RESET << std::endl;
	std::cout << BLUE << "|		Character " << Gaga->getName() << " has been created			|" << RESET << std::endl;
	std::cout << BLUE << "-----------------------------------------------------------------\n" << RESET << std::endl;

	// Création d'une source de materia pour chaque personnage
	IMateriaSource* srcGaga = new MateriaSource();

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
	Gaga->unequip(2);
	Gaga->unequip(42);

	std::cout << CYAN << "\n-->  Gaga s'équipe d'1 nouvelle materia" << RESET << std::endl;
	Gaga->equip(srcGaga->createMateria("cure"));
	Gaga->equip(srcGaga->createMateria("ice"));
	Gaga->equip(srcGaga->createMateria("cure")); // ne pourra pas s equipper car plus de place

	std::cout << BLUE << "\n	~~~ je delete ~~~" << RESET << std::endl;
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