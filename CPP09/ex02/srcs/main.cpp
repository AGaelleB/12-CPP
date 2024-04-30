#include "../includes/PmergeMe.hpp"
#include "../includes/Colors.hpp"


int main(int ac, char **av) {

	if (ac < 2) {
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}

	PmergeMe	list;

	list.execPmergeMe(ac, av);


	return 0;
}


/* 
	Algorithme de tri "merge-insert" :

	Combinaison de l'algorithme de tri fusion et de l'algorithme de tri par insertion.
	Divise la liste en sous-listes de taille appropriée pour le tri par insertion.
	Trie chaque sous-liste en utilisant l'algorithme de tri par insertion.
	Fusionne les sous-listes triées pour obtenir la liste entière triée.
	Avantages : tire parti des avantages du tri fusion pour diviser la liste et de l'efficacité du tri par insertion pour trier les sous-listes de petite taille.
	Peut offrir des performances optimales pour les listes partiellement triées ou de petite taille.


	Algorithme Ford-Johnson :

	Implémentation spécifique de l'algorithme de tri "merge-insert".
	Divise la liste en sous-listes de taille appropriée pour le tri par insertion.
	Trie chaque sous-liste en utilisant l'algorithme de tri par insertion.
	Fusionne les sous-listes triées pour obtenir la liste entière triée.
	Porte le nom de ses inventeurs, Donald B. Johnson et Selmer M. Johnson.
	Vise à combiner les avantages du tri fusion et du tri par insertion pour des performances optimales de tri.
	Utilisé dans divers contextes où des performances de tri efficaces sont nécessaires.

 */