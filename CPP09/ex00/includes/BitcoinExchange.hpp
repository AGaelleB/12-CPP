#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
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

class BitcoinExchange {

	private :
		std::string	_inputFile;
		std::map<std::string, double> _bitcoinPrices;
	
	public :

		BitcoinExchange();
		BitcoinExchange(std::string inputFile);
		BitcoinExchange & operator=(BitcoinExchange const & rhs);
		BitcoinExchange(BitcoinExchange const & obj);
		~BitcoinExchange();

		// getter
		std::string	getInputFile() const;

		//trimming functions
		std::string	trim(const std::string &str);
		std::string	trimTabsAndSpaces(const std::string &str);

		// parsing
		bool		checkFirstLine(std::string line);				// parsing format de la ligne (date | valeur)
		bool		checkFormaDate(std::string line);				// parsing format de la date (YYYY-MM-DD)
		bool		checkContentDate(std::string dateStr);			// parsing du contenur de la date 32j etc
		bool		checkConvertion(std::string line);				// Convertion de la valeur en double et vérifier si elle est dans la plage valide

		// data
		void		loadBitcoinPrices();							// Charge les prix du Bitcoin à partir du fichier CSV
		void		calculateExchangeRate(std::string lineToPrint);	// Utilise la date trouvée pour calculer le taux de change

		// result
		void		convertionExchangeRate(std::string inputFile);
};

#endif