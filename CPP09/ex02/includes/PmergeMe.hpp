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
		long parseInput(char* input);
		bool fillContainersVector(long num);
		bool fillContainersList(long num);
		int parseAndFillVector(int ac, char **av);
		int parseAndFillList(int ac, char **av);

		// sort std::vector
		void						minMaxVector(std::vector<int>& arr, int a, int b);
		std::vector<int>			fordJohnsonSortVector(std::vector<int> v);
		void						executeFordJohnsonSortVector();
		clock_t						sortVectorTime();

		// sort std::list
		std::list<int> 				fordJohnsonSortList(std::list<int> l);
		void						executeFordJohnsonSortList();
		clock_t						sortListTime();

		// time
		void						printTimeVector(clock_t timeElapsed, size_t nbElements);
		void						printTimeList(clock_t timeElapsed, size_t nbElements);
	void printTime(double timeElapsed, size_t nbElements, const std::string& containerType);

		// print
		void						displayInput() const; // Pour afficher la séquence d'entiers non triés
		void						displaySortedVector() const;
		void						displaySortedList() const;
		void						compareResults(clock_t vectorTime, clock_t listTime);

		// execution
		void						execPmergeMe(int ac, char **av);
};

#endif