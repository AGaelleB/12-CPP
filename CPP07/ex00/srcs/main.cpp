#include "../includes/whatever.hpp"

#define RED			"\033[1;31m"
#define GREEN		"\033[1;32m"
#define YELLOW		"\033[1;33m"
#define BLUE		"\033[1;34m"
#define MAGENTA		"\033[1;35m"
#define CYAN		"\033[1;36m"
#define WHITE		"\033[1m\033[37m"
#define RESET		"\033[0m"

void	subjectMain() {

	std::cout << RED << "\n	~~~ SUBJECT TESTS ~~~\n" << RESET << std::endl;

	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

void	myMain() {

	std::cout << RED << "\n\n	~~~ MY TESTS ~~~\n" << RESET << std::endl;
	std::cout << BLUE << "~~~ Test des templates avec des int ~~~\n" << RESET << std::endl;

	int a = 42;
	int b = -42;
	std::cout << WHITE << "-> Mes valeurs sont :\n" << RESET << "a = " << a << ", b = " << b << std::endl;
	
	std::cout << WHITE << "\n-> Je swap les valeurs : " << RESET << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	
	std::cout << WHITE << "\n-> Valeurs min et max : " << RESET << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	
	std::cout << std::endl;
	

	std::cout << BLUE << "~~~ Test des templates avec des strings ~~~\n" << RESET << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << WHITE << "-> Mes valeurs sont :\n" << RESET << "c = " << c << ", d = " << d << std::endl;
	
	std::cout << WHITE << "\n-> Je swap les valeurs : " << RESET << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;

	std::cout << WHITE << "\n-> Valeurs min et max : " << RESET << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

int	main(void)
{
	subjectMain();
	myMain();

	return 0;
}