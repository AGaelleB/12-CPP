
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


/**************************************** GETTERS / SETTERS ****************************************/



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
		for (std::vector<int>::size_type j = 0; j < _toBeSort.size(); j++) {
			if (_toBeSort[j] == static_cast<int>(num)) {
				std::cerr << "Error: Duplicate number for number [" << _toBeSort[j] << "]" << std::endl;
				return 1;
			}
		}

		_toBeSort.push_back(static_cast<int>(num));
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

	mergeSort(_toBeSort, 0, _toBeSort.size() - 1, minSize);  // Exécution du tri

	clock_t end = clock();  // Fin de la mesure du temps
	return end - start;  // Renvoie le temps écoulé en ticks
}



/******************************************** SORT LIST ********************************************/




/*********************************************** TIME **********************************************/

void PmergeMe::printTimeVector(clock_t timeElapsed, size_t nbElements) {
	double timeInSeconds = static_cast<double>(timeElapsed) / CLOCKS_PER_SEC;  // Convertir les ticks en secondes
	double timeInMilliseconds = timeInSeconds * 1000;  // Convertir les secondes en millisecondes
	std::cout << BOLD << "Time to process a range of " << nbElements << " elements with std::vector: " << RESET
	<< std::fixed << std::setprecision(5) << timeInMilliseconds << " ms" << std::endl;
}

void PmergeMe::printTimeList(clock_t timeElapsed, size_t nbElements) {
	double timeInSeconds = static_cast<double>(timeElapsed) / CLOCKS_PER_SEC;
	double timeInMilliseconds = timeInSeconds * 1000;
	std::cout << BOLD << "Time to process a range of " << nbElements << " elements with std::list: " << RESET
	<< std::fixed << std::setprecision(5) << timeInMilliseconds << " ms" << std::endl;
}

/********************************************** PRINT **********************************************/


void PmergeMe::displayInput() const {

	std::cout << RED << "Before sort:	";
	for (size_t i = 0; i < _toBeSort.size(); ++i) {
		std::cout << "[" << _toBeSort[i] << "] ";
	}
	std::cout << RESET << std::endl;
}


void PmergeMe::displaySorted() const {
	std::cout << GREEN << "After sort:	";
	for (std::list<int>::const_iterator it = _hasBeenSort.begin(); it != _hasBeenSort.end(); it++) {
		std::cout << "[" << *it << "] ";
	}
	std::cout << RESET << std::endl;
}


/******************************************** EXECUTION ********************************************/


void PmergeMe::execPmergeMe(int ac, char **av) {

	if (parseInput(ac, av) == 1)
		return;

	std::cout << BLUE << "\n~~~ Ford-Johnson algorithm sort with std::vector ~~~\n" << RESET << std::endl;
	displayInput();
	clock_t timeElapsed = sortVector();	// Capture le temps de tri et affiche les résultats triés
	_hasBeenSort.clear();  // Transfert des éléments triés du vector à la list
	for (size_t i = 0; i < _toBeSort.size(); ++i) {
		_hasBeenSort.push_back(_toBeSort[i]);
	}
	displaySorted();
	printTimeVector(timeElapsed, _toBeSort.size());


	std::cout << BLUE << "\n\n~~~ Ford-Johnson algorithm sort with std::list ~~~\n" << RESET << std::endl;


}

