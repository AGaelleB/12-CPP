
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

void PmergeMe::insertionSort(std::vector<int>& arr, int left, int right) {
	for (int i = left + 1; i <= right; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void PmergeMe::merge(std::vector<int>& arr, int l, int m, int r) {
	std::vector<int> left(arr.begin() + l, arr.begin() + m + 1);
	std::vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
	
	size_t i = 0, j = 0;  // Change 'int' to 'size_t' for i and j
	int k = l;
	while (i < left.size() && j < right.size()) {
		if (left[i] <= right[j]) {
			arr[k++] = left[i++];
		} else {
			arr[k++] = right[j++];
		}
	}

	while (i < left.size()) {
		arr[k++] = left[i++];
	}

	while (j < right.size()) {
		arr[k++] = right[j++];
	}
}


void PmergeMe::mergeSort(std::vector<int>& arr, int l, int r, int minSize) {
	if (l < r) {
		if (r - l + 1 <= minSize) {
			insertionSort(arr, l, r); // Use insertion sort for small segments
		} else {
			int m = l + (r - l) / 2;
			mergeSort(arr, l, m, minSize);
			mergeSort(arr, m + 1, r, minSize);
			merge(arr, l, m, r);
		}
	}
}


clock_t PmergeMe::sortVector() {
	int minSize = 16; // Seuil pour basculer vers le tri par insertion
	clock_t start = clock();  // Début de la mesure du temps

	mergeSort(_sortVector, 0, _sortVector.size() - 1, minSize);  // Exécution du tri

	clock_t end = clock();  // Fin de la mesure du temps
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
