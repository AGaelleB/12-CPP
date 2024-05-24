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

#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define BOLD	"\033[1;37m"
#define RESET	"\033[0m"
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
		long				parseInput(char* input);
		bool				fillContainersVector(long num);
		bool				fillContainersList(long num);
		int					parseAndFillVector(int ac, char **av);
		int					parseAndFillList(int ac, char **av);

		// sort std::vector
		std::vector<int>	fordJohnsonSortVector(std::vector<int> v);

		// sort std::list
		std::list<int>		fordJohnsonSortList(std::list<int> l);

		// time
		void				printTimeVector(clock_t timeElapsed, size_t nbElements);
		void				printTimeList(clock_t timeElapsed, size_t nbElements);

		// print
		void				displaySortedVector() const;
		void				displaySortedList() const;
		void				compareResults(clock_t vectorTime, clock_t listTime);

		// execution
		void				execPmergeMe(int ac, char **av);
};

#endif