
#include "../includes/PmergeMe.hpp"


/****************************************** FORME CANONIQUE ******************************************/


PmergeMe::PmergeMe() {
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs) {
	if (this == &rhs)
		return (*this);
	return (*this);
}

PmergeMe::PmergeMe(PmergeMe const & obj) {
	*this = obj;
}

PmergeMe::~PmergeMe() {
}


/********************************************* PARSING *********************************************/

int PmergeMe::parseInput(int ac, char **av) {

	char	*endPtr;
	long	num;

	for (int i = 1; i < ac; i++) {
		num = std::strtol(av[i], &endPtr, 10); // Convertir la chaîne en long

		// Vérif si la conversion a échoué
		if (*endPtr != '\0') {
			std::cerr << "Error: Non-numeric character" << std::endl;
			return 1;
		}
		if (num <= 0) {
			std::cerr << "Error: Non-positive integer" << std::endl;
			return 1;
		}
		if (num > INT_MAX) {
			std::cerr << "Error: integer overflow " << std::endl;
			return 1;
		}

		// Vérif si doublons de nb
		for (std::vector<int>::size_type j = 0; j < _sortVector.size(); j++) {
			if (_sortVector[j] == static_cast<int>(num)) {
				std::cerr << "Error: Duplicate number for number [" << _sortVector[j] << "]" << std::endl;
				return 1;
			}
		}

		_sortVector.push_back(static_cast<int>(num));
	}
	return 0;
}



/******************************************* SORT VECTOR *******************************************/

void PmergeMe::minMax(std::vector<int>& arr, int a, int b) {
	if (arr[a] > arr[b]) {
		std::swap(arr[a], arr[b]);  // S'assurer que la paire est ordonnée (min, max)
	}
}

void PmergeMe::merge(std::vector<int>& arr, int left, int mid, int right) {
	std::vector<int> temp(right - left + 1);

	int i = left;
	int j = mid + 1;
	int k = 0;

	// Fusionner les deux moitiés dans temp[]
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
		}
	}

	// Copier les éléments restants de la première moitié, s'il y en a
	while (i <= mid) {
		temp[k++] = arr[i++];
	}

	// Copier les éléments restants de la deuxième moitié, s'il y en a
	while (j <= right) {
		temp[k++] = arr[j++];
	}

	// Copier les éléments de temp[] à arr[]
	for (i = left, k = 0; i <= right; i++, k++) {
		arr[i] = temp[k];
	}
}

void PmergeMe::fordJohnson(std::vector<int>& arr, int left, int right) {

	// Debugging: Affiche l'état actuel du tableau
	std::cout << "Handling range [" << left << ", " << right << "]: ";
	for (int i = left; i <= right; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	// Étape 1: Comparer les éléments en paires
	if (right - left + 1 <= 2) {  // Cas de base pour les paires ou les éléments uniques
		if (right > left) minMax(arr, left, right);  // Comparaison et échange si nécessaire
		return;
	}

	// Étape 2: Construction de l'arbre de tournoi
	int mid = (left + right) / 2;
	// Compare les éléments à travers le milieu pour construire l'arbre de tournoi
	for (int i = left; i <= mid; ++i) {
		int j = mid + 1 + (i - left); // Comparer les éléments en formant des paires minimales
		if (j <= right) { // Ajoutez cette vérification pour vous assurer que j ne dépasse pas right
			minMax(arr, i, j);
		}
	}

	// Étape 3: Placer l'élément minimal et répéter
	fordJohnson(arr, left, mid);  // Tri récursif de la première moitié
	fordJohnson(arr, mid + 1, right);  // Tri récursif de la seconde moitié

	merge(arr, left, mid, right);  // Merge les deux sous-ensembles triés pour maintenir l'ordre


}

void PmergeMe::sortVectorFordJohnson() {
	if (_sortVector.size() < 2) return;  // Gestion du cas où il n'y a rien ou un seul élément à trier
	fordJohnson(_sortVector, 0, _sortVector.size() - 1);
}


clock_t PmergeMe::sortVector() {
	clock_t start = clock();  // Commence le chronométrage
	sortVectorFordJohnson();  // Exécute le tri Ford-Johnson
	clock_t end = clock();  // Termine le chronométrage
	return end - start;  // Renvoie le temps écoulé en ticks
}



/******************************************** SORT LIST ********************************************/

// Fonction pour diviser une liste
std::list<int>::iterator PmergeMe::split(std::list<int>& source) {
	std::list<int>::iterator fast = source.begin();
	std::list<int>::iterator slow = source.begin();
	// Avancer `fast` de deux pas à chaque itération, et `slow` d'un pas.
	while (fast != source.end() && ++fast != source.end()) {
		++fast;
		++slow;
	}
	return slow;
}


// Fonction pour fusionner deux listes
void PmergeMe::merge(std::list<int>& left, std::list<int>& right, std::list<int>& result) {
	std::list<int>::iterator it_left = left.begin();
	std::list<int>::iterator it_right = right.begin();
	while (it_left != left.end() && it_right != right.end()) {
		if (*it_left <= *it_right) {
			result.push_back(*it_left);
			++it_left;
		} else {
			result.push_back(*it_right);
			++it_right;
		}
	}
	while (it_left != left.end()) {
		result.push_back(*it_left);
		++it_left;
	}
	while (it_right != right.end()) {
		result.push_back(*it_right);
		++it_right;
	}
}


//Fonction pour le tri fusion sur une liste
void PmergeMe::mergeSort(std::list<int>& list) {
	if (list.size() <= 1) return;  // Cas de base, la liste est déjà triée

	std::list<int> left;
	std::list<int> right;
	std::list<int>::iterator mid = split(list);

	// Diviser la liste en deux moitiés 'left' et 'right'
	left.splice(left.begin(), list, list.begin(), mid);
	right.splice(right.begin(), list, mid, list.end());

	mergeSort(left);
	mergeSort(right);

	// Fusionner les deux listes triées dans la liste originale
	list.clear();
	merge(left, right, list);
}


clock_t PmergeMe::sortList() {
	clock_t start = clock();

	mergeSort(_sortList);

	clock_t end = clock();
	return end - start;
}


/*********************************************** TIME **********************************************/

void PmergeMe::printTimeVector(clock_t timeElapsed, size_t nbElements) {

	double timeInSec;
	double timeInMs;

	timeInSec = static_cast<double>(timeElapsed) / CLOCKS_PER_SEC;
	timeInMs = timeInSec * 1000;

	std::cout << BOLD << "Time to process a range of " << nbElements << " elements with std::vector:	" << RESET
	<< std::fixed << std::setprecision(5) << timeInMs << " ms" << std::endl;
}

void PmergeMe::printTimeList(clock_t timeElapsed, size_t nbElements) {

	double timeInSec;
	double timeInMs;

	timeInSec = static_cast<double>(timeElapsed) / CLOCKS_PER_SEC;
	timeInMs = timeInSec * 1000;

	std::cout << BOLD << "Time to process a range of " << nbElements << " elements with std::list:	" << RESET
	<< std::fixed << std::setprecision(5) << timeInMs << " ms" << std::endl;
}


/********************************************** PRINT **********************************************/


void PmergeMe::displayInput() const {

	std::cout << RED << "\nBefore sort:				";
	for (size_t i = 0; i < _sortVector.size(); ++i) {
		std::cout << "[" << _sortVector[i] << "] ";
	}
	std::cout << RESET << std::endl << std::endl;
}

void PmergeMe::displaySortedVector() const {
	std::cout << GREEN << "After sort with Vector container:	";
	for (size_t i = 0; i < _sortVector.size(); ++i) {
		std::cout << "[" << _sortVector[i] << "] ";
	}
	std::cout << RESET << std::endl;
}

void PmergeMe::displaySortedList() const {
	std::cout << GREEN << "After sort with List container:		";
	for (std::list<int>::const_iterator it = _sortList.begin(); it != _sortList.end(); ++it) {
		std::cout << "[" << *it << "] ";
	}
	std::cout << RESET << std::endl;
}


/******************************************** EXECUTION ********************************************/



void PmergeMe::execPmergeMe(int ac, char **av) {
	if (parseInput(ac, av) == 1)
		return;

	std::cout << BLUE << "\n	~~~ Ford-Johnson algorithm sort ~~~\n" << RESET << std::endl;
	displayInput();

	// Tri et affichage pour std::vector
	clock_t timeElapsedVector = sortVector();
	displaySortedVector();
	printTimeVector(timeElapsedVector, _sortVector.size());

	// Préparation pour le tri avec std::list
	_sortList.clear();  // Nettoyez la liste avant de transférer les éléments
	for (std::vector<int>::iterator it = _sortVector.begin(); it != _sortVector.end(); ++it) {
		_sortList.push_back(*it);  // Copie des éléments triés dans _sortList
	}

	std::cout << std::endl;

	// Tri et affichage pour std::list
	clock_t timeElapsedList = sortList();
	displaySortedList();
	printTimeList(timeElapsedList, _sortList.size());
}

// question tu utilise le merge insert ou ford johson, c est different mais pas clair dans le sujet 