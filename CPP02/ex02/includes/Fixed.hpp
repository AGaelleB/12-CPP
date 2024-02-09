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


/* FONCTIONS STATIQUES

	Imagine une bibliothèque où tu peux aller chercher des livres sans avoir
	besoin d'une carte de bibliothèque spécifique. Les fonctions membres statiques
	sont un peu comme ça dans le monde de la programmation : elles appartiennent
	à une classe et tu peux les utiliser sans avoir besoin de créer un objet
	spécifique de cette classe. Cela peut être super utile pour des tâches qui
	sont liées à la classe dans son ensemble plutôt qu'à un objet individuel.
	Par exemple, comparer deux nombres pour voir lequel est le plus grand ou le
	plus petit, comme dans ton cas avec les fonctions min et max.

 */

/* OPERATEURS DE SURCHARGES

	Les versions préfixes de ces opérateurs incrémentent ou décrémentent la valeur
	de l'objet, puis retournent l'objet lui-même après modification.

	Les versions postfixes prennent un paramètre entier (généralement non utilisé)
	pour les distinguer syntaxiquement des versions préfixes. Elles incrémentent
	ou décrémentent la valeur de l'objet, mais retournent une copie de l'objet
	avant la modification.

 */

/* OPERATEURS D'INCREMENTATION ET DECREMENTATION

	Imagine que tu as une télécommande qui ne fonctionne qu'avec un seul appareil.
	Les opérateurs de surcharge te permettent de modifier cette télécommande pour
	qu'elle puisse contrôler plusieurs appareils de manières différentes.
	En programmation, surcharger un opérateur signifie que tu donnes à cet
	opérateur (comme +, -, *, /, etc.) une nouvelle manière de fonctionner quand
	il est utilisé avec des objets de ta classe. Cela te permet d'ajouter,
	soustraire, multiplier ou diviser des objets de ta classe de manière intuitive,
	comme si c'étaient des nombres.

 */

/* INTERETS DES REFERENCES

	Utiliser des références, c'est un peu comme avoir le numéro de téléphone de
	quelqu'un plutôt que de devoir aller le voir en personne chaque fois que tu
	veux lui parler. Les références permettent à tes fonctions de travailler
	directement avec les objets existants sans avoir à les copier (ce qui pourrait
	être lent et utiliser beaucoup de mémoire). Cela rend ton programme plus rapide
	et plus efficace, surtout quand tu travailles avec de gros objets ou des
	opérations qui doivent être très rapides, comme les comparaisons ou les calculs
	arithmétiques.

 */