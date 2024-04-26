
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

