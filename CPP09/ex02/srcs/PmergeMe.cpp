
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

long PmergeMe::parseInput(char* input) {
	char* endPtr;
	long num = strtol(input, &endPtr, 10); // Convert string to long

	// Vérif si la conversion a échoué
	if (*endPtr != '\0') {
		std::cerr << "Error: Non-numeric character" << std::endl;
		exit(-1);
	}
	if (num <= 0) {
		std::cerr << "Error: Non-positive integer" << std::endl;
		exit(-1);
	}
	if (num > INT_MAX) {
		std::cerr << "Error: integer overflow " << std::endl;
		exit(-1);
	}
	return num;
}

bool PmergeMe::fillContainersVector(long num) {
	if (std::find(_sortVector.begin(), _sortVector.end(), static_cast<int>(num)) != _sortVector.end()) {
		std::cerr << "Error: Duplicate number for vector [" << num << "]" << std::endl;
		return false;
	}
	_sortVector.push_back(static_cast<int>(num));
	return true;
}

bool PmergeMe::fillContainersList(long num) {
	if (std::find(_sortList.begin(), _sortList.end(), static_cast<int>(num)) != _sortList.end()) {
		std::cerr << "Error: Duplicate number for list [" << num << "]" << std::endl;
		return false;
	}
	_sortList.push_back(static_cast<int>(num));
	return true;
}

int PmergeMe::parseAndFillVector(int ac, char **av) {
	long num;
	for (int i = 1; i < ac; i++) {
		num = parseInput(av[i]);
		if (num == -1)
			exit(-1);
		if (!fillContainersVector(num)) {
			exit(-1);
		}
	}
	return 0;
}

int PmergeMe::parseAndFillList(int ac, char **av) {
	long num;
	for (int i = 1; i < ac; i++) {
		num = parseInput(av[i]);
		if (num == -1)
			exit(-1);
		if (!fillContainersList(num)) {
			exit(-1);
		}
	}
	return 0;
}


/******************************************* SORT VECTOR *******************************************/

// Function to compare and order pairs
void PmergeMe::minMaxVector(std::vector<int>& arr, int a, int b) {
	if (arr[a] > arr[b])
		std::swap(arr[a], arr[b]);
}

// Ford-Johnson sort implementation based on your friend's approach
std::vector<int> PmergeMe::fordJohnsonSortVector(std::vector<int> v) {
	if (v.size() <= 1)
		return v;

	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < v.size(); i += 2) {
		if (v[i] > v[i + 1])
			pairs.push_back(std::make_pair(v[i + 1], v[i]));
		else
			pairs.push_back(std::make_pair(v[i], v[i + 1]));
	}

	std::vector<int> remaining_elements;
	if (v.size() % 2 != 0)
		remaining_elements.push_back(v.back());

	std::vector<int> sorted_vector;
	for (size_t i = 0; i < pairs.size(); ++i)
		sorted_vector.push_back(pairs[i].first);

	std::sort(sorted_vector.begin(), sorted_vector.end());

	for (size_t i = 0; i < pairs.size(); ++i) {
		std::vector<int>::iterator it = std::upper_bound(sorted_vector.begin(), sorted_vector.end(), pairs[i].second);
		sorted_vector.insert(it, pairs[i].second);
	}

	for (size_t i = 0; i < remaining_elements.size(); ++i) {
		std::vector<int>::iterator it = std::upper_bound(sorted_vector.begin(), sorted_vector.end(), remaining_elements[i]);
		sorted_vector.insert(it, remaining_elements[i]);
	}

	return sorted_vector;
}


/******************************************** SORT LIST ********************************************/

std::list<int> PmergeMe::fordJohnsonSortList(std::list<int> l) {
	if (l.size() <= 1)
		return l;

	std::list<std::pair<int, int> > pairs;
	std::list<int>::iterator it = l.begin();
	while (std::distance(it, l.end()) > 1) {
		int first = *it;
		int second = *(++it);
		if (first > second)
			pairs.push_back(std::make_pair(second, first));
		else
			pairs.push_back(std::make_pair(first, second));
		++it;
	}

	std::list<int> remaining_elements;
	if (it != l.end())
		remaining_elements.push_back(*it);

	std::list<int> sorted_list;
	for (std::list<std::pair<int, int> >::iterator pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it)
		sorted_list.push_back(pair_it->first);

	sorted_list.sort();

	for (std::list<std::pair<int, int> >::iterator pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it) {
		std::list<int>::iterator insert_pos = std::upper_bound(sorted_list.begin(), sorted_list.end(), pair_it->second);
		sorted_list.insert(insert_pos, pair_it->second);
	}

	for (std::list<int>::iterator remaining_it = remaining_elements.begin(); remaining_it != remaining_elements.end(); ++remaining_it) {
		std::list<int>::iterator insert_pos = std::upper_bound(sorted_list.begin(), sorted_list.end(), *remaining_it);
		sorted_list.insert(insert_pos, *remaining_it);
	}

	return sorted_list;
}


/*********************************************** TIME **********************************************/

void PmergeMe::printTimeVector(clock_t timeElapsed, size_t nbElements) {

	double timeInUs;

	timeInUs = timeElapsed * (1000000.0 / CLOCKS_PER_SEC);

	std::cout << BOLD << "Time to process a range of " << nbElements << " elements with std::vector: "
	<< std::fixed << std::setprecision(0) << timeInUs << " us" << RESET << std::endl;
}

void PmergeMe::printTimeList(clock_t timeElapsed, size_t nbElements) {

	double timeInUs;

	timeInUs = timeElapsed * (1000000.0 / CLOCKS_PER_SEC);

	std::cout << BOLD << "Time to process a range of " << nbElements << " elements with std::list:   "
	<< std::fixed << std::setprecision(0) << timeInUs << " us" << RESET << std::endl;
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
	std::cout << GREEN << "\nAfter sort with List container:   ";
	for (std::list<int>::const_iterator it = _sortList.begin(); it != _sortList.end(); ++it) {
		std::cout << "[" << *it << "] ";
	}
	std::cout << RESET << std::endl;
}

void PmergeMe::compareResults(clock_t vectorTime, clock_t listTime) {
	std::vector<int> vectorResults(_sortVector.begin(), _sortVector.end());
	std::vector<int> listResults(_sortList.begin(), _sortList.end());

	if (vectorResults == listResults) {
		std::cout << BLUE << "\n========> Success: No difference between sorted results! <========\n" << RESET;
	}
	else {
		std::cout << RED << "\n========> Failed: Differences detected between sorted results <========\n" << RESET;
	}

	if (vectorTime < listTime) {
		std::cout << BLUE << "========>		std::vector was faster		 <========\n\n" << RESET;
	}
	else if (listTime < vectorTime) {
		std::cout << BLUE << "========>		std::list was faster		 <========\n\n" << RESET;
	}
	else {
		std::cout << BLUE << "========>  Both containers took the same amount of time  <========\n" << RESET;
	}
}


/******************************************** EXECUTION ********************************************/


void PmergeMe::execPmergeMe(int ac, char **av) {
	std::cout << BLUE << "\n~~~ Ford-Johnson algorithm sort ~~~\n" << RESET << std::endl;

	// Fill and sort vector
	clock_t vectorStart = clock();
	if (parseAndFillVector(ac, av) != 0) { // Check if there was an error
		return;
	}
	_sortVector = fordJohnsonSortVector(_sortVector);
	clock_t vectorEnd = clock();

	// Fill and sort list
	clock_t listStart = clock();
	if (parseAndFillList(ac, av) != 0) { // Check if there was an error
		return;
	}
	_sortList = fordJohnsonSortList(_sortList);
	clock_t listEnd = clock();

	// Affiche les éléments avant le tri
	std::cout << RED << "Before sort:	";
	for (size_t i = 1; i < _sortVector.size(); ++i) {
		std::cout << "[" << av[i] << "] ";
	}
	std::cout << RESET << std::endl << std::endl;

	// // Affiche les éléments avant le tri pour la list
	// std::cout << RED << "Before sort (List):	";
	// for (std::list<int>::iterator it = _sortList.begin(); it != _sortList.end(); ++it) {
	// 	std::cout << "[" << *it << "] ";
	// }
	// std::cout << RESET << std::endl << std::endl;


	// Display results
	displaySortedVector();
	displaySortedList();

	// Timing information
	std::cout << std::endl;
	printTimeVector((vectorEnd - vectorStart), _sortVector.size());
	printTimeList((listEnd - listStart), _sortList.size());

	// Compare results
	compareResults((vectorEnd - vectorStart), (listEnd - listStart));
}




// void PmergeMe::execPmergeMe(int ac, char **av) {
//     std::cout << BLUE << "\n~~~ Ford-Johnson algorithm sort ~~~\n" << RESET << std::endl;

//     clock_t vectorStart = clock();
//     clock_t listStart = clock();
//     bool errorOccurred = false;

//     for (int i = 1; i < ac; ++i) {
//         long num = parseInput(av[i]);
//         if (num == -1) {
//             errorOccurred = true;
//             break; // If any error occurs, stop processing further.
//         }

//         if (!fillContainersVector(num)) {
//             errorOccurred = true;
//             break;
//         }

//         if (!fillContainersList(num)) {
//             errorOccurred = true;
//             break;
//         }
//     }

//     if (errorOccurred) {
//         return; // Stop processing if there was an error.
//     }

//     _sortVector = fordJohnsonSortVector(_sortVector);
//     clock_t vectorEnd = clock();

//     _sortList = fordJohnsonSortList(_sortList);
//     clock_t listEnd = clock();

//     // Display results
//     std::cout << RED << "Vector sort results:\n";
//     displaySortedVector();
//     std::cout << RED << "\nList sort results:\n";
//     displaySortedList();

//     // Timing information
//     printTimeVector((vectorEnd - vectorStart), _sortVector.size());
//     printTimeList((listEnd - listStart), _sortList.size());

//     // Compare results
//     compareResults((vectorEnd - vectorStart), (listEnd - listStart));
// }
