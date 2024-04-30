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
	std::vector<int>	_sortVector;
	std::list<int>		_sortList;
 

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
		std::list<int>::iterator	split(std::list<int>& source);
		void						merge(std::list<int>& left, std::list<int>& right, std::list<int>& result);
		void						mergeSort(std::list<int>& list);
		clock_t						sortList();


		// time
		void printTimeVector(clock_t timeElapsed, size_t nbElements);
		void printTimeList(clock_t timeElapsed, size_t nbElements);

		// print
		void	displayInput() const; // Pour afficher la séquence d'entiers non triés
		void	displaySortedVector() const;
		void	displaySortedList() const;



		// execution
		void	execPmergeMe(int ac, char **av);


};

#endif