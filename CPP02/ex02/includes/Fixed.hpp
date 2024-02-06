#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define RESET	"\033[0m"

class Fixed {

	private :
		int					_value;
		static const int	_fractionalBits = 8;

	public :
		 // construteur par default, de copie, de conversion et destructeur
		Fixed();
		Fixed(const Fixed& src);
		Fixed(const int nbInt);
		Fixed(const float nbFloat);
		~Fixed();

		// Opérateur d'affectation, surcharge d'operateur '='
		Fixed& operator=(const Fixed& src);

		// opérateurs de comparaison
		bool	operator>(const Fixed& src) const;
		bool	operator<(const Fixed& src) const;
		bool	operator>=(const Fixed& src) const;
		bool	operator<=(const Fixed& src) const;
		bool	operator==(const Fixed& src) const;
		bool	operator!=(const Fixed& src) const;

		// opérateurs arithmétiques
		Fixed	operator+(const Fixed& src) const;
		Fixed	operator-(const Fixed& src) const;
		Fixed	operator*(const Fixed& src) const;
		Fixed	operator/(const Fixed& src) const;

		// opérateurs d’incrémentation et de décrémentation
		Fixed&	operator++(void); // prefix
		Fixed	operator++(int); // postfix
		Fixed&	operator--(void); // prefix
		Fixed	operator--(int); // postfix

		// getter setter
		int		getRawBits( void ) const; // retourne la valeur du nombre à virgule fixe sans la convertir
		void	setRawBits( int const raw ); // initialise la valeur du nombre à virgule fixe avec celle passée en paramètre

		// fonctions membres
		float	toFloat( void ) const;
		int		toInt( void ) const;

		// fonctions statics membres
		static Fixed&		min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&		max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
};

// surcharge de l’opérateur d’insertion
std::ostream& operator<<(std::ostream& os, const Fixed& src);

#endif
