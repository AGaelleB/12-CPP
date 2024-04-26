
#include "../includes/RPN.hpp"


/****************************************** FORME CANONIQUE ******************************************/


RPN::RPN() {
}

RPN::RPN(std::string numbers) {
	this->_numbers = numbers;
}

RPN & RPN::operator=(RPN const & rhs) {
	if (this == &rhs)
		return (*this);
	this->_numbers = rhs._numbers;
	return (*this);
}

RPN::RPN(RPN const & obj) {
	*this = obj;
}

RPN::~RPN() {
}


/**************************************** GETTERS / SETTERS ****************************************/

std::string	RPN::getNumbers() const {
	return(this->_numbers);
}


/********************************************* PARSING *********************************************/

void RPN::checkData(std::string _numbers) {
	for (size_t i = 0; i < _numbers.size(); ++i) {
		if (!isdigit(_numbers[i]) && !isOperator(std::string(1, _numbers[i])) && _numbers[i] != ' ') {
			std::cerr << "Error: Invalid input" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
}

void RPN::checkNumbers(std::string numbers) {
	std::string token;
	for (size_t i = 0; i < numbers.size(); ++i) {
		token.clear();
		while (i < numbers.size() && numbers[i] != ' ') {
			token += numbers[i];
			++i;
		}
		if (!token.empty() && !isOperator(token)) {
			int num = std::atoi(token.c_str());
			if (num >= 10 || num < 0) {
				std::cerr << "Error: Numbers must be between 0 and 10" << std::endl;
				exit(EXIT_FAILURE);
			}
		}
	}
}

void RPN::parsing(std::string _numbers) {
	checkData(_numbers);
	checkNumbers(_numbers);
}

/********************************************* CALCULS *********************************************/

bool RPN::isOperator(std::string const & token) const {
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::performOperation(int operand1, int operand2, std::string const & op) {

	if (op == "+") return operand1 + operand2;
	else if (op == "-") return operand1 - operand2;
	else if (op == "*") return operand1 * operand2;
	else if (op == "/") {
		if (operand2 == 0) {
			throw std::runtime_error("Error: Division by zero");
		}
		return operand1 / operand2;
	}
	throw std::runtime_error("Error: Unknown operator");
}

int RPN::calculate(std::string const & numbers) {

	std::istringstream iss(numbers);
	std::string token;

	while (iss >> token) {
		if (isOperator(token)) {
			if (_operands.size() < 2) {
				throw std::runtime_error("Error: Insufficient operands for operation");
			}
			int operand2 = _operands.top(); // Retire les deux derniers opérandes de la pile
			_operands.pop();
			int operand1 = _operands.top();
			_operands.pop();
			_operands.push(performOperation(operand1, operand2, token)); // Effectue l'opération et empile le résultat
		}
		else {
			_operands.push(std::atoi(token.c_str()));
		}
	}

	// print le result lorsqu'il reste qu'une seule valeur dans la pile
	if (_operands.size() == 1) {
		std::cout << _operands.top() << std::endl;
		return _operands.top();
	}
	else {
		std::cerr << "Error: Too many operands" << std::endl;
		return 0;
	}

	return _operands.top();
}

