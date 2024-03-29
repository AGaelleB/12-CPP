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

	std::cout << BOLD << "I print the element at the top of the stack:" << RESET;
	std::cout << mstack.top() << std::endl << std::endl;

	mstack.pop();

	std::cout << BOLD << "I print the size of the stack:" << RESET;
	std::cout << mstack.size() << std::endl << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << BOLD << "I use a iterator to print the stack:" << RESET << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void	myMain() {

	MutantStack<int> mstack;

	// Ajout d'éléments à la pile
	mstack.push(5);
	mstack.push(17);
	mstack.push(42);
	mstack.push(21);

	// Impression de la pile sur une copie tempStack
	MutantStack<int> tempStack = mstack;
	std::cout << BLUE << "Stack elements:" << std::endl;
	std::cout << BOLD << "---" << RESET << std::endl;
	while (!tempStack.empty()) {
		std::cout << tempStack.top() << std::endl;
		tempStack.pop();
	}
	std::cout << BOLD << "---" << RESET << std::endl;

	// Suppression de l'élément au sommet
	std::cout << BOLD << "\nSize of the stack elements before pop: " << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "Size of the stack elements after pop: " << mstack.size() << RESET << std::endl << std::endl;

	// Ajout de plusieurs éléments
	mstack.push(3);
	mstack.push(5);
	mstack.push(-42);
	mstack.push(0);

	// Impression de la pile sur une copie tempStack
	MutantStack<int> tempStack2 = mstack;
	std::cout << BLUE << "Stack elements after new add:" << std::endl;
	std::cout << BOLD << "---" << RESET << std::endl;
	while (!tempStack2.empty()) {
		std::cout << tempStack2.top() << std::endl;
		tempStack2.pop();
	}
	std::cout << BOLD << "---" << RESET << std::endl;

	// Itération à travers MutantStack avec un itérateur standard
	std::cout << BOLD << "\nStandard iteration:" << RESET << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << std::endl;
	}

	// Itération à travers MutantStack avec un itérateur inverse
	std::cout << BOLD << "\nReverse iteration:" << RESET << std::endl;
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
		std::cout << *rit << std::endl;
	}
}


int main() {

	std::cout << BLUE << "\n	~~~ Tests subject main ~~~\n" << RESET << std::endl;
	subjectMain();

	std::cout << BLUE << "\n	~~~ Tests my main ~~~\n" << RESET << std::endl;
	myMain();

	return 0;
}
