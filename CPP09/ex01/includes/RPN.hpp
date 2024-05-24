#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>
#include <string>
#include <sstream>

#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define BOLD	"\033[1;37m"
#define RESET	"\033[0m"

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
		int			doOperation(int operand1, int operand2, std::string const & op);
		int			calculator(std::string const & numbers);
};

#endif