#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Colors.hpp"

class BitcoinExchange {

	private :
		std::string	_inputFile;
		std::map<std::string, double> bitcoinPrices; // Container map pour stocker les prix du Bitcoin
	
	public :

		BitcoinExchange();
		BitcoinExchange(std::string inputFile);
		BitcoinExchange & operator=(BitcoinExchange const & rhs);
		BitcoinExchange(BitcoinExchange const & obj);
		~BitcoinExchange();

		// getter
		std::string	getInputFile() const;

		// parsing
		bool		checkFirstLine(std::string line);				// parsing format de la ligne (date | valeur)
		bool		checkFormaDate(std::string line);				// parsing format de la date (YYYY-MM-DD)
		bool		checkContentDate(std::string dateStr);			// parsing du contenur de la date 32j etc
		bool		checkConvertion(std::string line);				// Convertion de la valeur en double et vérifier si elle est dans la plage valide

		// data
		void		loadBitcoinPrices();							// Charge les prix du Bitcoin à partir du fichier CSV
		void		calculateExchangeRate(std::string lineToPrint);	// Utilise la date trouvée pour calculer le taux de change

		void		convertionExchangeRate(std::string inputFile);
};

#endif
