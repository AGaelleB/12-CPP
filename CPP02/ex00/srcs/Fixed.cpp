#include "../includes/Fixed.hpp"


/*********************** CONSTRUCTEURS ET DESTRUCTEUR  ***********************/

Fixed::Fixed() : _value(0) {
	std::cout << BLUE << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	std::cout << BLUE << "Copy constructor called" << RESET << std::endl;
	this->_value = src.getRawBits();
}

Fixed::~Fixed() {
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

/************************** OPERATEUR D'AFFECTATION  *************************/

Fixed& Fixed::operator=(const Fixed& src) {
	
	std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;

	if (this != &src) {
		this->_value = src.getRawBits();
	}
	return *this;
}

/**************************** GETTERS ET SETTERS *****************************/

int	Fixed::getRawBits( void ) const {
	std::cout << GREEN << "getRawBits member function called" << RESET << std::endl;
	return (this->_value);
}

void Fixed::setRawBits( int const raw ) {

	std::cout << GREEN << "setRawBits called" << RESET << std::endl;
	this->_value = raw;
}


/* NOTE EXPLICATIVE

	Opérateur d'affectation (« égal ») :
	C'est comme si tu avais deux jouets, disons A et B. A a un numéro secret à l'intérieur,
	et tu veux que B ait le même numéro.
	L'opérateur d'affectation, c'est comme si tu copiais le numéro de A et le collais sur B.

	Constructeur par copie :
	Supposons que tu aies un jouet appelé A qui a un numéro secret.
	Maintenant, tu veux faire un nouveau jouet, B, qui soit exactement pareil que A.
	Le constructeur par copie, c'est comme si tu créais B en reprenant les attributs de A

 */