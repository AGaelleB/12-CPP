#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define RESET	"\033[0m"

class Fixed {

	private :
		int					_value; // valeur du nb en virgule fixe
		static const int	_fractionalBits = 8; // nb de bits de la partie fractionnaire

	public :
		 // construteur par default, de recopie et destructeur
		Fixed();
		Fixed(const Fixed& src);
		~Fixed();

		// Opérateur d'affectation
		Fixed &operator=(const Fixed &src);

		int	getRawBits( void ) const; // retourne la valeur du nombre à virgule fixe sans la convertir
		void setRawBits( int const raw ); // initialise la valeur du nombre à virgule fixe avec celle passée en paramètre
};

#endif
