#include "../includes/Fixed.hpp"

int	main( void ) {

Fixed a; // Default constructor
Fixed b( a ); // Copy constructor
Fixed c;

c = b;

std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;

return 0;
}


/* NOTE EXPLICATIVE

	la valeur reste à 0 car les objets sont initialisés et copiés de manière
	à conserver la valeur par défaut de 0, comme spécifié dans le constructeur
	par défaut de la classe Fixed.

	imaginons que tu aies une boîte spéciale appelée "Fixed" qui contient un nombre.

	Fixed a :
	Au début, ta première boîte "a" est vide (la valeur est 0).
	Tu prends une autre boîte "b" et tu mets la même valeur que dans la boîte "a"
	à l'intérieur (c'est toujours 0).
	
	Fixed c :
	Ensuite, tu prends une troisième boîte "c", elle aussi est vide (la valeur est 0).
	Tu copies la valeur de la boîte "b" dans la boîte "c" (encore 0).
	
	Tu regardes à l'intérieur de chaque boîte :
	Boîte "a" : 0
	Boîte "b" : 0 (parce que tu as mis la même chose que dans "a")
	Boîte "c" : 0 (parce que tu as mis la même chose que dans "b")
	En résumé, toutes les boîtes contiennent 0 car tu as commencé avec une boîte vide
	et tu as copié le 0 dans les autres boîtes

 */