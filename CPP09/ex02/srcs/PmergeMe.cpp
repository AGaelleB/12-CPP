
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

// Fonction pour comparer et ordonner les paires
void PmergeMe::minMaxVector(std::vector<int>& arr, int a, int b) {
	if (arr[a] > arr[b])
		std::swap(arr[a], arr[b]);
}

void PmergeMe::mergeVector(std::vector<int>& arr, int left, int mid, int right) {
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

	// Copier les éléments restants de la 1er moitié
	while (i <= mid) {
		temp[k++] = arr[i++];
	}

	// Copier les éléments restants de la 2nd moitié
	while (j <= right) {
		temp[k++] = arr[j++];
	}

	// Copier les éléments de temp[] à arr[]
	for (i = left, k = 0; i <= right; i++, k++) {
		arr[i] = temp[k];
	}
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& arr, int left, int right) {

 	// // Debugging: Affiche l'état actuel du tableau
	// std::cout << "Handling range [" << left << ", " << right << "]: ";
	// for (int i = left; i <= right; ++i) {
	// 	std::cout << arr[i] << " ";
	// }
	// std::cout << std::endl;


	// Étape 1: Comparer les éléments en paires
	if (right - left + 1 <= 2) {  // Cas de base pour les paires ou les éléments uniques
		if (right > left) minMaxVector(arr, left, right);  // Comparaison et échange si nécessaire
		return;
	}

	// Étape 2: Construction de l'arbre de tournoi
	int mid = (left + right) / 2;
	// Compare les éléments à travers le milieu pour construire l'arbre de tournoi
	for (int i = left; i <= mid; ++i) {
		int j = mid + 1 + (i - left); // Comparer les éléments en formant des paires minimales
		if (j <= right)
			minMaxVector(arr, i, j);
	}

	// Étape 3: Placer l'élément minimal et répéter
	fordJohnsonSortVector(arr, left, mid);  // Tri récursif de la première moitié
	fordJohnsonSortVector(arr, mid + 1, right);  // Tri récursif de la seconde moitié

	mergeVector(arr, left, mid, right);  // Merge les deux sous-ensembles triés pour maintenir l'ordre
}

void PmergeMe::executeFordJohnsonSortVector() {
	fordJohnsonSortVector(_sortVector, 0, _sortVector.size() - 1);
}


clock_t PmergeMe::sortVectorTime() {
	clock_t	start = clock();
	executeFordJohnsonSortVector();
	clock_t	end = clock();
	return (end - start);
}


/******************************************** SORT LIST ********************************************/

// Fonction pour comparer et ordonner les paires
void PmergeMe::minMaxList(std::list<int>::iterator a, std::list<int>::iterator b) {
	if (*a > *b) {
		std::iter_swap(a, b);
	}
}

// Fonction pour trouver le milieu d'une list, utilisée pour diviser la list en deux sous-list
std::list<int>::iterator PmergeMe::findMiddle(std::list<int> &lst, int size) {
	std::list<int>::iterator mid = lst.begin();
	std::advance(mid, size / 2); // Avance l'itérateur de la moitié de la taille de la list
	return mid;
}

// Fonction récursive pour trier la list
void PmergeMe::fordJohnsonSortList(std::list<int>& lst) {
	int size = std::distance(lst.begin(), lst.end()); // Calculer la taille de la list
	if (size <= 2) { // Si la liste contient deux éléments ou moins
		if (size == 2) {
			std::list<int>::iterator first = lst.begin();
			std::list<int>::iterator second = lst.begin();
			++second;
			minMaxList(first, second);
		}
		return;
	}

	// Étape 1: Comparaison des éléments en paires
	std::list<int>::iterator mid = findMiddle(lst, size);
	std::list<int>::iterator midPlusOne = mid;
	++midPlusOne;

	std::list<int>::iterator it1 = lst.begin();
	std::list<int>::iterator it2 = midPlusOne;
	while (it1 != midPlusOne && it2 != lst.end()) {
		minMaxList(it1, it2);
		++it1;
		++it2;
	}

	// Étape 2: Construction de l'arbre de tournoi
	std::list<int> left;
	std::list<int>::iterator it = lst.begin();
	while (it != midPlusOne) {
		left.push_back(*it);
		++it;
	}

	std::list<int> right;
	it = midPlusOne;
	while (it != lst.end()) {
		right.push_back(*it);
		++it;
	}

	fordJohnsonSortList(left);
	fordJohnsonSortList(right);

	// Étape 3: Fusion des listes triées
	lst.clear();
	lst.insert(lst.end(), left.begin(), left.end());
	lst.insert(lst.end(), right.begin(), right.end());
}

void PmergeMe::executeFordJohnsonSortList() {
	fordJohnsonSortList(_sortList);
}

clock_t PmergeMe::sortListTime() {
	clock_t start = clock();
	executeFordJohnsonSortList();
	clock_t end = clock();
	return (end - start);
}


/*********************************************** TIME **********************************************/

void PmergeMe::printTimeVector(clock_t timeElapsed, size_t nbElements) {

	double timeInSec;
	double timeInMs;

	timeInSec = static_cast<double>(timeElapsed) / CLOCKS_PER_SEC;
	timeInMs = timeInSec * 1000;

	std::cout << BOLD << "Time to process a range of " << nbElements << " elements with std::vector: "
	<< std::fixed << std::setprecision(5) << timeInMs << " ms" << RESET << std::endl;
}

void PmergeMe::printTimeList(clock_t timeElapsed, size_t nbElements) {

	double timeInSec;
	double timeInMs;

	timeInSec = static_cast<double>(timeElapsed) / CLOCKS_PER_SEC;
	timeInMs = timeInSec * 1000;

	std::cout << BOLD << "Time to process a range of " << nbElements << " elements with std::list: "
	<< std::fixed << std::setprecision(5) << timeInMs << " ms" << RESET << std::endl;
}


/********************************************** PRINT **********************************************/


void PmergeMe::displayInput() const {

	std::cout << RED << "\nBefore sort: ";
	for (size_t i = 0; i < _sortVector.size(); ++i) {
		std::cout << "[" << _sortVector[i] << "] ";
	}
	std::cout << RESET << std::endl << std::endl;
}

void PmergeMe::displaySortedVector() const {
	std::cout << GREEN << "After sort with Vector container: ";
	for (size_t i = 0; i < _sortVector.size(); ++i) {
		std::cout << "[" << _sortVector[i] << "] ";
	}
	std::cout << RESET << std::endl;
}

void PmergeMe::displaySortedList() const {
	std::cout << GREEN << "After sort with List container: ";
	for (std::list<int>::const_iterator it = _sortList.begin(); it != _sortList.end(); ++it) {
		std::cout << "[" << *it << "] ";
	}
	std::cout << RESET << std::endl;
}

void PmergeMe::compareResults() {
	std::vector<int> vectorResults(_sortVector.begin(), _sortVector.end());
	std::vector<int> listResults(_sortList.begin(), _sortList.end());

	if (vectorResults == listResults) {
		std::cout << GREEN << "\nSuccess: No difference between sorted results!" << RESET << std::endl;
	}
	else {
		std::cout << RED << "\nFailed: Differences detected between sorted results" << RESET << std::endl;
	}
}


/******************************************** EXECUTION ********************************************/


void PmergeMe::execPmergeMe(int ac, char **av) {
	if (parseInput(ac, av) == 1)
		return;

	std::cout << BLUE << "\n	~~~ Ford-Johnson algorithm sort ~~~\n" << RESET << std::endl;
	displayInput();

	clock_t timeElapsedVector = sortVectorTime();
	displaySortedVector();
	printTimeVector(timeElapsedVector, _sortVector.size());

	_sortList.clear();
	for (std::vector<int>::iterator it = _sortVector.begin(); it != _sortVector.end(); ++it) {
		_sortList.push_back(*it); // Copie des éléments triés dans _sortList
	}
	std::cout << std::endl;

	clock_t timeElapsedList = sortListTime();
	displaySortedList();
	printTimeList(timeElapsedList, _sortList.size());
	
	compareResults();
}

