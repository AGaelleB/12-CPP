#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <iostream>
#include <sstream>	// Pour std::istringstream
#include <limits>	// Pour std::numeric_limits
#include <cmath>	// Pour std::isnan, std::isinf
#include <string>


#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define RESET	"\033[0m"


class ScalarConverter {

	public :
		static void		convert(const std::string& input); // convertie la valeure literale en types: char, int, float, double
	
		char			getCastChar(void) const;
		int				getCastInt(void) const;
		float			getCastFloat(void) const;
		double			getCastDouble(void) const;


	private :
		ScalarConverter(); // en privée pour ne pas que la class soit instanciable
		ScalarConverter(const ScalarConverter& rhs);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& rhs);
	
		static void		_checkIfValid(const std::string& input);

		// vérifier le type de valeur littérale
		static bool		_isCharLiteral(const std::string& input);
		static bool		_isIntLiteral(const std::string& input);
		static bool		_isFloatLiteral(const std::string& input);
		static bool		_isDoubleLiteral(const std::string& input);
		static bool		_containsNonNumeric(const std::string& input);

		// stocker les valeurs converties
		char			_castChar;
		int				_castInt;
		float			_castFloat;
		double			_castDouble;

		// conversion
		char			_convertFromChar(void);
		int				_convertFromInt(void);
		float			_convertFromFloat(void);
		double			_convertFromDouble(void);

		// afficher les résultats
		void		_printResult(int index);
};


#endif

/* TABLEAU DES CONVERSIONS

	********************************************************************************
	*   Cast              | Conv.    | Reint.   | Upcast   | Downcast | Type qual. *
	* --------------------|----------|----------|----------|----------|----------- *
	* Implicit            | Yes      |          | Yes      |          |            *
	* static_cast         | Yes      |          | Yes      | Yes      |            *
	* dynamic_cast        |          |          | Yes      | Yes      |            *
	* const_cast          |          |          |          |          | Yes        *
	* reinterpret_cast    |          | Yes      | Yes      | Yes      |            *
	********************************************************************************

	********************************************************************************
	*    Cast             | Semantic check   | Reliable at run | Tested at run     *
	* --------------------|------------------|-----------------|------------------ *
	* Implicit            | Yes              | Yes             |                   *
	* static_cast         | Yes              |                 |                   *
	* dynamic_cast        | Yes              | Yes             | Yes               *
	* const_cast          |                  |                 |                   *
	* reinterpret_cast    |                  |                 |                   *
	********************************************************************************

 */