#include "../includes/MutantStack.hpp"

#define RED			"\033[1;31m"
#define GREEN		"\033[1;32m"
#define YELLOW		"\033[1;33m"
#define BLUE		"\033[1;34m"
#define MAGENTA		"\033[1;35m"
#define CYAN		"\033[1;36m"
#define BOLD		"\033[1m\033[37m"
#define RESET		"\033[0m"

/* 
	std::stack contient : 
		push() pour ajouter un élément au sommet de la pile
		pop() pour supprimer l'élément du sommet de la pile
		top() pour accéder à l'élément du sommet sans le supprimer

 */

void	subjectMain() {

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void	myMain() {
	// Création d'une instance de MutantStack pour des entiers
	MutantStack<int> mstack;

	// Ajout d'éléments à la pile
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element: " << mstack.top() << std::endl;

	// Suppression de l'élément au sommet
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;

	// Ajout de plusieurs éléments
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	// Itération à travers MutantStack avec un itérateur standard
	std::cout << "Standard iteration:" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << std::endl;
	}

	// Itération à travers MutantStack avec un itérateur inverse
	std::cout << "Reverse iteration:" << std::endl;
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
		std::cout << *rit << std::endl;
	}

	// Création d'une copie de MutantStack
	MutantStack<int> s(mstack);
	std::cout << "Copied stack size: " << s.size() << std::endl;
}

int main() {

	// std::cout << BLUE << "\n	~~~ Tests subject main ~~~\n" << RESET << std::endl;
	// subjectMain();

	std::cout << BLUE << "\n	~~~ Tests my main ~~~\n" << RESET << std::endl;
	myMain();

	return 0;
}
