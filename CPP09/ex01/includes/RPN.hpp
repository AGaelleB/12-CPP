#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>
#include <string>
#include <sstream> // Inclure pour std::istringstream

#include "Colors.hpp"

class RPN {

	private :

	std::string			_numbers;
	std::stack<int>		_operands;


	public :

		RPN();
		RPN(std::string numbers);
		RPN & operator=(RPN const & rhs);
		RPN(RPN const & obj);
		~RPN();

		// getter
		std::string	getNumbers() const;

		// parsing
		void		checkData(std::string numbers);
		void		checkNumbers(std::string numbers);
		void		parsing(std::string numbers);

		// calculs
		bool		isOperator(std::string const & token) const;
		int			performOperation(int operand1, int operand2, std::string const & op);
		int			calculate(std::string const & numbers);



};

#endif