#include "../includes/Fixed.hpp"


/*********************** CONSTRUCTEURS ET DESTRUCTEUR  ***********************/

Fixed::Fixed() : _value(0) {
	std::cout << BLUE << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& src) : _value(src._value) {
	std::cout << BLUE << "Copy constructor called" << RESET << std::endl;
}

Fixed::Fixed(const int nbInt) : _value(nbInt << _fractionalBits) {
	std::cout << BLUE << "Int constructor called" << RESET << std::endl;
}

Fixed::Fixed(const float nbFloat) : _value(roundf(nbFloat * (1 << _fractionalBits))) {
	std::cout << BLUE << "Float constructor called" << RESET << std::endl;
}

Fixed::~Fixed() {
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

/************************** OPERATEUR D'AFFECTATION  *************************/

Fixed& Fixed::operator=(const Fixed& src) {
	std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;

	if (this != &src)
		_value = src._value;

	return (*this);
}

/***************************** FONCTIONS MEMBRES *****************************/

float Fixed::toFloat( void ) const {
	return ( (float)this->_value / (1 << _fractionalBits) );
}

int Fixed::toInt( void ) const {
	return ( this->_value >> _fractionalBits );	
}

std::ostream& operator<<(std::ostream& os, const Fixed& src) {
	os << src.toFloat(); // fonction toFloat pour obtenir la représentation en virgule flottante
	return (os);
}


/* NOTE EXPLICATIVE


 */