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

		// fonctions membres
		float toFloat( void ) const;
		int toInt( void ) const;

		int	getRawBits( void ) const; // retourne la valeur du nombre à virgule fixe sans la convertir
		void setRawBits( int const raw ); // initialise la valeur du nombre à virgule fixe avec celle passée en paramètre
};

// surcharge de l’opérateur d’insertion
std::ostream& operator<<(std::ostream& os, const Fixed& src);

#endif

/* Forme canonique
	pour etre une forme canonique il faut :
	- un construteur par default
	- un construteur par copie
	- un operateur d'assigniation
	- un destructeur
 */

/* Surcharge de l’opérateur d’insertion
	surcharge de l’opérateur d’insertion («) qui insère une représentation en
	virgule flottante du nombre à virgule fixe dans le flux de sortie (objet output 
	stream) passé en paramètre

	Imagine que tu as une classe en C++ appelée Fixed qui représente des nombres à 
	virgule fixe. Maintenant, tu veux pouvoir afficher ces nombres dans la console
	de manière pratique, comme tu le fais normalement avec des entiers ou des nombres
	à virgule flottante.

	La "surcharge de l'opérateur d'insertion" (<<) est une fonction spéciale que
	tu peux créer dans ta classe Fixed. C'est comme si tu disais au C++ :
	"quand quelqu'un utilise << avec un objet de ma classe, voici comment
	tu dois afficher ça !"

	C'est ce qu'on appelle la "surcharge de l'opérateur d'insertion", car tu modifies
	la façon dont l'opérateur << fonctionne pour ton objet Fixed.
	Cela rend l'affichage de ton objet dans la console vraiment facile et lisible.
 */