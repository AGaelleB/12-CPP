#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cctype>
#include <ctime>
#include <iomanip>

#include "Colors.hpp"

#define INT_MAX 2147483647

class PmergeMe {

	private :
	std::vector<int>	_toBeSort; // pour stocker la séquence d'entiers non triés
	std::list<int>		_hasBeenSort; // pour stocker la séquence triée
 

	public :

		PmergeMe();
		PmergeMe & operator=(PmergeMe const & rhs);
		PmergeMe(PmergeMe const & obj);
		~PmergeMe();

		// parsing
		int		parseInput(int ac, char **av);

		// sort std::vector
		void	insertionSort(std::vector<int>& arr, int left, int right);
		void	merge(std::vector<int>& arr, int l, int m, int r);
		void	mergeSort(std::vector<int>& arr, int l, int r, int minSize);
		clock_t	sortVector();


		// sort std::list


		// time
		void printTimeVector(clock_t timeElapsed, size_t nbElements);
		void printTimeList(clock_t timeElapsed, size_t nbElements);

		// print
		void	displayInput() const; // Pour afficher la séquence d'entiers non triés
		void	displaySorted() const; // Pour afficher la séquence triée

		// execution
		void	execPmergeMe(int ac, char **av);


};

#endif