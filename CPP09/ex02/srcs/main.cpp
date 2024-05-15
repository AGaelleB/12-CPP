#include "../includes/PmergeMe.hpp"
#include "../includes/Colors.hpp"

// ./PmergeMe `shuf -i 1-100 -n 10`

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
	Combinaison de tri par insertion et tri par fusion.
	Utilise le tri par insertion pour les petits segments (efficace sur de petits ensembles).
	Utilise le tri par fusion pour combiner les segments (efficace sur de grands ensembles).

	Algorithme Ford-Johnson :
	Connu aussi sous le nom de tri par paire.
	Réduit le nombre de comparaisons nécessaires.
	Organise les éléments en paires, les trie, puis les regroupe stratégiquement pour optimiser les comparaisons.
 
	Principe de base du tri Ford-Johnson :
	1.Diviser : Divisez les données en paires et triez chaque paire.
	2.Construire un arbre de tournoi : Utilisez les éléments plus petits de chaque paire pour construire un arbre de tournoi et déterminer l'élément le plus petit.
	3.Positionner : Une fois l'élément le plus petit trouvé, utilisez l'autre élément de sa paire pour aider à positionner le prochain élément le plus petit en utilisant le moins de comparaisons.
 
 */


/* 
	std::vector
	Accès rapide : Permet un accès rapide aux éléments par indexation.
	Efficient pour la lecture : Bon pour les opérations qui accèdent souvent à des éléments de manière séquentielle.
	Caractéristiques + : stocke les éléments de manière contiguë en mémoire, ce qui optimise l'accès aux éléments par indexation
	Caractéristiques - : l'insertion ou la suppression d'éléments est longue

	std::list
	Modifications efficaces : Idéal pour les insertions et suppressions fréquentes, car il ne nécessite pas de déplacer les autres éléments.
	Flexibilité : Permet des modifications n'importe où dans la liste sans coût élevé.
	Caractéristiques + :  éléments sous forme de liste doublement chaînée, ce qui permet des insertions et suppressions rapides à n'importe quel point de la liste sans nécessiter de déplacements d'autres éléments
	Caractéristiques - : l'accès aux éléments n'est pas aussi rapide que dans un vecteur car il faut parcourir la liste

	Utilisation conjointe
	Complémentarité : std::vector est optimal pour l'accès, tandis que std::list est optimal pour les modifications fréquentes, combinant efficacité en lecture et flexibilité en écriture.
 */