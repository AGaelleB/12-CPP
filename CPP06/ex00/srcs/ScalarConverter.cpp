#include "../includes/ScalarConverter.hpp"

/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

ScalarConverter::ScalarConverter() : _castChar(0), _castInt(0), _castFloat(0.0f), _castDouble(0.0) {
	// std::cout << CYAN << "~ScalarConverter~ default constructor called" << RESET << std::endl;
	return;
}


ScalarConverter::ScalarConverter(const ScalarConverter& rhs):	_castChar(rhs._castChar),
																_castInt(rhs._castInt),
																_castFloat(rhs._castFloat),
																_castDouble(rhs._castDouble) {
	// std::cout << CYAN << "~ScalarConverter~ copy constructor called" << RESET << std::endl;
	*this = rhs;
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

	// Vérifie que ce ne soit pas vide
	if (input.empty()) {
		std::cout << "Invalid argument : it's empty" << std::endl;
		return ;
	}

	// a ameliorer
}

bool ScalarConverter::_ParticularCase(const std::string& input) {
	if (input == "nan" || input == "nanf") {
		
		std::cout << "char:	impossible" << std::endl;
		std::cout << "int:	impossible" << std::endl;
		std::cout << "float:	nanf" << std::endl;
		std::cout << "double:	nan\n" << std::endl;
		return true; // Indique que le cas a été géré
	}
	return false; // Indique que le cas n'a pas été géré
}


/****************************** DETECTION DU TYPE ******************************/

bool ScalarConverter::_isCharLiteral(const std::string& input) {
	if (input.length() == 1 && !std::isdigit(input[0])) {
		return true;
	} else {
		return false;
	}
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

	for (size_t i = start; i < input.length(); i++) {
		if (!isdigit(input[i]))
			return false;
	}

	return true;
}


// Float : 32 bits en mémoire, environ 7 chiffres
bool ScalarConverter::_isFloatLiteral(const std::string& input) {

	bool hasPoint = false;
	bool hasDigitBeforePoint = false;
	bool hasDigitAfterPoint = false;
	bool hasSuffixF = false;

	for (size_t i = 0; i < input.length(); i++) {
		if (input[i] == '.') {
			if (!hasDigitBeforePoint)
				return false;
			hasPoint = true;
		}
		
		else if (std::isdigit(input[i])) {
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

	if (hasPoint && hasSuffixF && hasDigitBeforePoint && hasDigitAfterPoint)
		return true;
	else
		return false;
}

// Double : 64 bits en mémoire, environ 15 à 16 chiffres
bool ScalarConverter::_isDoubleLiteral(const std::string& input) {

	bool hasPoint = false;
	bool hasDigitBeforePoint = false;
	bool hasDigitAfterPoint = false;
	bool hasSuffixF = false;

	for (size_t i = 0; i < input.length(); i++) {
		if (input[i] == '.') {
			if (!hasDigitBeforePoint)
				return false;
			hasPoint = true;
		}
		
		else if (std::isdigit(input[i])) {
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

	if (hasPoint && !hasSuffixF && hasDigitBeforePoint && hasDigitAfterPoint) // ici je verif qu il n y a pas de f
		return true;
	else
		return false;
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

/* 
	il faudra que je bloque les conversion impossible (ex valeurs trop grandes pour être converties en un type plus petit)
 */

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
	_castInt = static_cast<int>(_castFloat);
	_castDouble = static_cast<double>(_castFloat);
	_castChar = static_cast<char>(_castFloat);
	return _castFloat;
}

double ScalarConverter::_convertFromDouble(const std::string& input) {
	std::istringstream iss(input);
	iss >> _castDouble;
	_castInt = static_cast<int>(_castDouble);
	_castFloat = static_cast<float>(_castDouble);
	_castChar = static_cast<char>(_castDouble);
	return _castDouble;
}

int ScalarConverter::_convertFromInt(const std::string& input) {
	std::istringstream iss(input);
	iss >> _castInt;
	_castFloat = static_cast<float>(_castInt);
	_castDouble = static_cast<double>(_castInt);
	_castChar = static_cast<char>(_castInt);
	return _castInt;
}


void ScalarConverter::convert(const std::string& input) {
	_checkIfValid(input); // Vérifie si l'entrée est valide.
	if (_ParticularCase(input)) {
		return; // Si le cas particulier a été géré, termine l'exécution de la fonction
	}

	ScalarConverter converter; // Crée une instance de la classe

	int index = 0;
	if (converter._isCharLiteral(input)) {
		std::cout << "Detected type: Char\n" << std::endl;
		converter._convertFromChar(input);
		index = 1;
	}
	
	else if (converter._isIntLiteral(input)) {
		std::cout << "Detected type: Int\n" << std::endl;
		converter._convertFromInt(input);
		index = 2;
	}
	
	else if (converter._isFloatLiteral(input)) {
		std::cout << "Detected type: Float\n" << std::endl;
		converter._convertFromFloat(input);
		index = 3;
	}
	
	else if (converter._isDoubleLiteral(input)) {
		std::cout << "Detected type: Double\n" << std::endl;
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


void ScalarConverter::_shortPrintResult(void) {

	if (std::isprint(_castChar))
		std::cout << "char:	" << _castChar << std::endl;
	else
		std::cout << "char:	Non displayable" << std::endl;
	std::cout << "int:	" << _castInt << std::endl;
	std::cout << "float:	" << std::fixed << std::setprecision(1) << _castFloat << "f" << std::endl; // pour avoir les chiffres apres la virgule
	std::cout << "double:	" << std::fixed << std::setprecision(1) << _castDouble << std::endl << std::endl; // pour avoir les chiffres apres la virgule

}

void ScalarConverter::_printResult(int index) {

	if (index == 1)
		ScalarConverter::_shortPrintResult();
	// else
	// 	std::cout << "char:	impossible\n";

	if (index == 2)
		ScalarConverter::_shortPrintResult();
	// else
	// 	std::cout << "int:	impossible\n";

	if (index == 3)
		ScalarConverter::_shortPrintResult();
	// else
	// 	std::cout << "float:	impossible\n";

	if (index == 4)
		ScalarConverter::_shortPrintResult();
	// else
	// 	std::cout << "double:	impossible\n\n";
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

