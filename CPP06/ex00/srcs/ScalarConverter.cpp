#include "../includes/ScalarConverter.hpp"

/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

ScalarConverter::ScalarConverter() {
	// std::cout << CYAN << "~ScalarConverter~ default constructor called" << RESET << std::endl;

	this->_castChar = 0;
	this->_castInt = 0;
	this->_castFloat = 0.0f;
	this->_castDouble = 0.0;

	return;
}


ScalarConverter::ScalarConverter(const ScalarConverter& rhs) {
	// std::cout << CYAN << "~ScalarConverter~ copy constructor called" << RESET << std::endl;
	
	this->_castChar = rhs._castChar;
	this->_castInt = rhs._castInt;
	this->_castFloat = rhs._castFloat;
	this->_castDouble = rhs._castDouble;

	return;
}

ScalarConverter::~ScalarConverter() {
	// std::cout << RED << "~ScalarConverter~ destructor called" << RESET << std::endl;
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
	// std::cout << CYAN << "~ScalarConverter~ copy assignment operator called" << RESET << std::endl;
	this->_castChar = rhs._castChar;
	this->_castInt = rhs._castInt;
	this->_castFloat = rhs._castFloat;
	this->_castDouble = rhs._castDouble;

	return (*this);
}


/****************************** FONCTIONS MEMBRES ******************************/

void ScalarConverter::_checkIfValid(const std::string& input) {

	if (input.empty()) {
		std::cout << "Invalid argument : it's empty" << std::endl;
		return ;
	}
}

bool ScalarConverter::_particularCase(const std::string& input) {

	if (input == "nan" || input == "nanf") {
		
		std::cout << "char:	impossible" << std::endl;
		std::cout << "int:	impossible" << std::endl;
		std::cout << "float:	nanf" << std::endl;
		std::cout << "double:	nan\n" << std::endl;
		return true;
	}
	if (input == "-inf" || input == "-inff") {
		
		std::cout << "char:	impossible" << std::endl;
		std::cout << "int:	impossible" << std::endl;
		std::cout << "float:	-inff" << std::endl;
		std::cout << "double:	-inf\n" << std::endl;
		return true;
	}
	if (input == "inf" || input == "inff" || input == "+inf" || input == "+inff") {
		
		std::cout << "char:	impossible" << std::endl;
		std::cout << "int:	impossible" << std::endl;
		std::cout << "float:	inff" << std::endl;
		std::cout << "double:	inf\n" << std::endl;
		return true;
	}
	return false;
}


/****************************** DETECTION DU TYPE ******************************/

bool ScalarConverter::_isCharLiteral(const std::string& input) {
	if (input.length() == 1 && !std::isdigit(input[0]))
		return true;
	else
		return false;
}

bool ScalarConverter::_isIntLiteral(const std::string& input) {

	if (input.empty())
		return false;

	size_t start = 0;
	if (input[0] == '-') {
		if (input.length() == 1)
			return false; // str is just "-"
		start = 1;
	}

	long long intVal = 0;
	for (size_t i = start; i < input.length(); i++) {
		if (!isdigit(input[i]))
			return false;
		intVal = intVal * 10 + (input[i] - '0');
	}

	return true;
}

bool ScalarConverter::_isFloatLiteral(const std::string& input) {

	if (input.empty())
		return false;
	
	size_t start = 0;
	if (input[0] == '-')
		start = 1;

	bool hasPoint = false;
	bool hasDigitBeforePoint = false;
	bool hasDigitAfterPoint = false;
	bool hasSuffixF = false;

	for (size_t i = start; i < input.length(); i++) {
		if (input[i] == '.') {
			if (hasPoint)
				return false; // Plus d'un point dans le nombre
			hasPoint = true;
		}
		else if (isdigit(input[i])) {
			if (!hasPoint)
				hasDigitBeforePoint = true;
			else
				hasDigitAfterPoint = true;
		}
		else if (input[i] == 'f' && i == input.length() - 1)
			hasSuffixF = true;
		else
			return false;
	}

	return hasPoint && hasSuffixF && hasDigitBeforePoint && hasDigitAfterPoint;
}

bool ScalarConverter::_isDoubleLiteral(const std::string& input) {
	if (input.empty()) return false;
	
	size_t start = 0;
	if (input[0] == '-') {
		start = 1;
	}

	bool hasPoint = false;
	bool hasDigitBeforePoint = false;
	bool hasDigitAfterPoint = false;

	for (size_t i = start; i < input.length(); i++) {
		if (input[i] == '.') {
			if (hasPoint)
				return false; // Plus d'un point dans le nombre
			hasPoint = true;
		}
		else if (isdigit(input[i])) {
			if (!hasPoint)
				hasDigitBeforePoint = true;
			else
				hasDigitAfterPoint = true;
		}
		else
			return false;
	}

	return hasPoint && hasDigitBeforePoint && hasDigitAfterPoint && input[input.length() - 1] != 'f'; // Pas de 'f' à la fin pour un double
}


/****************************** GETTERS ******************************/


char	ScalarConverter::getCastChar(void) const {
	return(this->_castChar);
}

int		ScalarConverter::getCastInt(void) const {
	return(this->_castInt);
}

float	ScalarConverter::getCastFloat(void) const {
	return(this->_castFloat);

}

double	ScalarConverter::getCastDouble(void) const {
	return(this->_castDouble);
}

/****************************** CONVERSIONS ******************************/

char ScalarConverter::_convertFromChar(const std::string& input) {
	_castChar = input[0];
	_castInt = static_cast<int>(_castChar);
	_castFloat = static_cast<float>(_castChar);
	_castDouble = static_cast<double>(_castChar);
	return _castChar;
}

float ScalarConverter::_convertFromFloat(const std::string& input) {
	std::istringstream iss(input); // permet de lire les valeurs numériques à partir de la chaîne d'entrée
	iss >> _castFloat;
	if (static_cast<double>(_castFloat) <= INT_MAX && static_cast<double>(_castFloat) >= INT_MIN)
		_castInt = static_cast<int>(_castFloat);
	else
		_castInt = INT_OVERFLOW;
	_castDouble = static_cast<double>(_castFloat);
	_castChar = static_cast<char>(_castFloat);
	return _castFloat;
}

double ScalarConverter::_convertFromDouble(const std::string& input) {
	std::istringstream iss(input);
	iss >> _castDouble;
	if (_castDouble <= INT_MAX && _castDouble >= INT_MIN)
		_castInt = static_cast<int>(_castDouble);
	else
		_castInt = INT_OVERFLOW;
	_castFloat = static_cast<float>(_castDouble);
	_castChar = static_cast<char>(_castDouble);
	return _castDouble;
}

int ScalarConverter::_convertFromInt(const std::string& input) {
	std::istringstream iss(input);
	long long tempInt;
	iss >> tempInt;

	if (tempInt < 127 && tempInt > 31)
		_castChar = static_cast<char>(tempInt);
	if (tempInt <= INT_MAX && tempInt >= INT_MIN)
		_castInt = static_cast<int>(tempInt);
	else
		_castInt = INT_OVERFLOW;
	_castFloat = static_cast<float>(tempInt);
	_castDouble = static_cast<double>(tempInt);
	return _castInt;
}

void ScalarConverter::convert(const std::string& input) {
	_checkIfValid(input);
	if (_particularCase(input)) {
		return;
	}

	ScalarConverter converter; // Crée une instance de la classe

	int index = 0;
	if (converter._isCharLiteral(input)) {
		converter._convertFromChar(input);
		index = 1;
	}
	
	else if (converter._isIntLiteral(input)) {
		converter._convertFromInt(input);
		index = 2;
	}
	
	else if (converter._isFloatLiteral(input)) {
		converter._convertFromFloat(input);
		index = 3;
	}
	
	else if (converter._isDoubleLiteral(input)) {
		converter._convertFromDouble(input);
		index = 4;
	}
	
	else {
		std::cout << RED << "Error: Input can't be cast. Unsupported or invalid literal type\n" << RESET << std::endl;
		return ;
	}

	converter._printResult(index);
}


/****************************** UTILS ******************************/

std::string ScalarConverter::_formatNumber(double number) {
	std::ostringstream oss;
	if ((std::abs(number) > 0 && std::abs(number) < 1e-5) || std::abs(number) > 1e8) {
		oss << std::scientific << std::setprecision(5);
	} else {
		oss << std::fixed << std::setprecision(4);
	}
	oss << number;

	std::string str = oss.str();
	// Supprimer les zéros inutiles après la virgule
	size_t end = str.find_last_not_of('0');
	if (end != std::string::npos) {
		if (str[end] == '.') {
			end--;
		}
		str.erase(end + 1, std::string::npos);
	}

	// Ajouter ".0" si c'est un entier
	if (str.find('.') == std::string::npos) {
		str += ".0";
	}

	return str;
}

void ScalarConverter::_shortPrintResult(void) {
	if (std::isprint(_castChar))
		std::cout << "char:	'" << _castChar << "'" << std::endl;
	else
		std::cout << "char:	Non displayable" << std::endl;
	if (_castInt != INT_OVERFLOW)
		std::cout << "int:	" << _castInt << std::endl;
	else
		std::cout << "int:	Non displayable" << std::endl;

	std::cout << "float:	" << _formatNumber(_castFloat) << "f" << std::endl;
	std::cout << "double:	" << _formatNumber(_castDouble) << std::endl << std::endl;
}

void ScalarConverter::_printResult(int index) {

	if (index == 1)
		ScalarConverter::_shortPrintResult();

	if (index == 2)
		ScalarConverter::_shortPrintResult();

	if (index == 3)
		ScalarConverter::_shortPrintResult();

	if (index == 4)
		ScalarConverter::_shortPrintResult();
}


/* CAST EN C++

	C++ autorise systematiquement les casts implicitent (un int vers un double)

	** implicit cast **
	un int vers un double, vers un type plus precise


	** static cast **
	cast d'une valeure "b" vers un "int" s ecrit : 
	int a = 42;
	double b = a;
	int d = static_cast<int>(b); // ici je cast donc un double en un int
	Le static_cast est vérifié lors de la compilation et peut entraîner une perte de données si la conversion n'est pas sûre.


	** le dynamic cast ** 
	a lieu lors de l'execution
	s'utilise en cas de polymorphisme (doit avoir une methode virtuel)


	** Reinterpret cast **
	utile pour le retypage par exemple d'un void vers un char


	** const cast **
	exemple : 
		int a = 42;
		int cont *b = &a;
		int *c = b;
		int *d = const_cast<int *>(b);
	mieux vaut ne pas utiliser le const cast, veut souvent dire qu'on a un probleme de design de notre code

 */


/* Non displayable et impossible

	"Non displayable" : lors d une conversion d un caractère en d'autres types.
	Si le caractère n'est pas imprimable, afficher "Non displayable".

	"Impossible" : Lorsqu une conversion ne peut pas être effectuée.
	ex: convertir un caractère qui n'est pas un chiffre en un type numérique
 */

