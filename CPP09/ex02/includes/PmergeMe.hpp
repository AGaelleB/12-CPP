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
#include <algorithm>

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
		void						minMaxVector(std::vector<int>& arr, int a, int b);
		void						mergeVector(std::vector<int>& arr, int left, int mid, int right);
		void						fordJohnsonSortVector(std::vector<int>& arr, int left, int right);
		void						executeFordJohnsonSortVector();
		clock_t						sortVectorTime();

		// sort std::list
		void						minMaxList(std::list<int>::iterator a, std::list<int>::iterator b);
		std::list<int>::iterator	findMiddle(std::list<int> &lst, int size);
		void						fordJohnsonList(std::list<int>& lst);
		void						executeFordJohnsonSortList();
		clock_t						sortListTime();

		// time
		void						printTimeVector(clock_t timeElapsed, size_t nbElements);
		void						printTimeList(clock_t timeElapsed, size_t nbElements);

		// print
		void						displayInput() const; // Pour afficher la séquence d'entiers non triés
		void						displaySortedVector() const;
		void						displaySortedList() const;

		// execution
		void						execPmergeMe(int ac, char **av);


};

#endif