
#include "../includes/BitcoinExchange.hpp"


/****************************************** FORME CANONIQUE ******************************************/

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(std::string inputFile) {
	this->_inputFile = inputFile;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs) {
	if (this == &rhs)
		return (*this);
	
	this->_inputFile = rhs._inputFile;
	return (*this);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & obj) {
	*this = obj;
}

BitcoinExchange::~BitcoinExchange() {
}


/**************************************** GETTERS / SETTERS ****************************************/

std::string	BitcoinExchange::getInputFile() const {
	return(this->_inputFile);
}


/****************************************** TRIMMING FUNCTIONS ******************************************/

std::string BitcoinExchange::trim(const std::string &str) {
	size_t first = str.find_first_not_of(' ');
	if (first == std::string::npos)
		return "";
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, last - first + 1);
}

std::string BitcoinExchange::trimTabsAndSpaces(const std::string &str) {
	size_t first = str.find_first_not_of(" \t");
	if (first == std::string::npos)
		return "";
	size_t last = str.find_last_not_of(" \t");
	return str.substr(first, last - first + 1);
}


/********************************************* PARSING *********************************************/

bool BitcoinExchange::checkFirstLine(std::string line) {
	if (line != "date | value") {
		std::cerr << "Error: invalid format for the first line \"" << line << "\"" << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::checkContentDate(std::string dateStr) {
	int year, month, day;

	std::istringstream(dateStr.substr(0, 4)) >> year;
	std::istringstream(dateStr.substr(5, 2)) >> month;
	std::istringstream(dateStr.substr(8, 2)) >> day;

	if (year < 2009 || (year == 2009 && month < 1) || (year == 2009 && month == 1 && day < 2)) {
		std::cerr << "Error: invalid date before January 2, 2009" << std::endl;
		return false;
	}
	if (month < 1 || month > 12 || day < 1 || day > 31) {
		std::cerr << "Error: invalid date" << std::endl;
		return false;
	}
	if (((month == 4 || month == 6 || month == 9 || month == 11) && day > 30 ) || (month == 2 && day > 28)) {
		std::cerr << "Error: invalid date" << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::checkFormaDate(std::string line) {
	std::string dateStr = line.substr(0, 10);
	if (dateStr.size() != 10 || dateStr[4] != '-' || dateStr[7] != '-') {
		std::cerr << "Error: invalid date format" << std::endl;
		return false;
	}
	std::string trimmedLine = trim(line.substr(10));
	if (trimmedLine.size() < 2 || trimmedLine[0] != '|' || trimmedLine[1] != ' ') {
		std::cerr << "Error: Bad input => " << line << std::endl;
		return false;
	}
	if (!checkContentDate(dateStr))
		return false;
	return true;
}

bool BitcoinExchange::checkConvertion(std::string line) {
	std::string trimmedLine = trim(line.substr(10));
	std::string valueStr = trim(trimmedLine.substr(2));
	double value;
	std::istringstream ss(valueStr);
	ss >> value;

	if (ss.fail() || !ss.eof()) {
		std::cerr << "Error: fail in line \"" << line << "\"" << std::endl;
		return false;
	}
	else if (value < 0) {
		std::cerr << "Error: not a positive number" << std::endl;
		return false;
	}
	else if (value > 1000) {
		std::cerr << "Error: too large number" << std::endl;
		return false;
	}
	return true;
}


/*********************************************** DATA ***********************************************/

void BitcoinExchange::loadBitcoinPrices() {

	std::ifstream file("data.csv");
	if (!file.is_open()) {
		std::cerr << "Error: cannot open bitcoin prices file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line); // Skip header

	std::string date;
	double price;
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		if (std::getline(iss, date, ',') && (iss >> price))
			_bitcoinPrices[date] = price;
		else
			std::cerr << "Error parsing line: " << line << std::endl;
	}
	file.close();
}

void BitcoinExchange::calculateExchangeRate(std::string lineToPrint) {
	loadBitcoinPrices();
	
	std::string::size_type pos = lineToPrint.find(" | ");
	std::string date = lineToPrint.substr(0, pos); // Extraire la date
	std::string valueStr = trim(lineToPrint.substr(pos + 3)); // Extraire la valeur sous forme de chaîne
	
	// Convertir en double
	std::istringstream iss(valueStr);
	double value;
	iss >> value;

	std::map<std::string, double>::iterator it;
	it = _bitcoinPrices.lower_bound(date); // trouve la date la plus proche ou exacte

	if (it != _bitcoinPrices.begin() && (it == _bitcoinPrices.end() || it->first != date)) // recule pour obtenir la date précédente la plus proche
		--it;

	// it pointe sur la date la plus proche antérieure ou sur la date exacte
	double price = it->second;
	double conversionResult = value * price;

	std::cout << date << " => " << value << " = " << conversionResult << std::endl;
}

/******************************************* RESULT *******************************************/

void BitcoinExchange::convertionExchangeRate(std::string inputFile) {
	std::ifstream file(inputFile.c_str());
	bool boolFirstLine = true;
	if (!file.is_open()) {
		std::cerr << "Error: can't open the file" << std::endl;
		return;
	}

	std::string line;
	while (std::getline(file, line)) {
		if (boolFirstLine == true) {
			if (!checkFirstLine(line))
				break;
			boolFirstLine = false;
			continue;
		}
		if (checkFormaDate(line) && checkConvertion(line))
			calculateExchangeRate(line);
	}
}
