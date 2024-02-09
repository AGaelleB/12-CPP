#include "../includes/Fixed.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Fixed::Fixed() : _value(0) {
}

Fixed::Fixed(const Fixed& src) : _value(src._value) {
}

Fixed::Fixed(const int nbInt) : _value(nbInt << _fractionalBits) {
}

Fixed::Fixed(const float nbFloat) : _value(roundf(nbFloat * (1 << _fractionalBits))) {
}

Fixed::~Fixed() {
}

/************************** OPERATEURS DE COMPARAISONS *************************/

bool	Fixed::operator>(const Fixed& src) const {
	return (this->_value > src._value);
}

bool	Fixed::operator<(const Fixed& src) const {
	return (this->_value < src._value);
}

bool	Fixed::operator>=(const Fixed& src) const {
	return (this->_value >= src._value);
}

bool	Fixed::operator<=(const Fixed& src) const {
	return (this->_value <= src._value);
}

bool	Fixed::operator==(const Fixed& src) const {
	return (this->_value == src._value);
}

bool	Fixed::operator!=(const Fixed& src) const {
	return (this->_value != src._value);
}


/*************************** OPERATEURS ARITHMETIQUES **************************/

Fixed	Fixed::operator+(const Fixed& src) const {

	Fixed	result;

	result._value = this->_value + src._value;

	return (result);
}

Fixed	Fixed::operator-(const Fixed& src) const {

	Fixed	result;

	result._value = this->_value - src._value;

	return (result);
}

Fixed	Fixed::operator*(const Fixed& src) const {

	Fixed	result;

	// Pour la multiplication, il faut prendre en compte la partie fractionnaire
	result._value = (this->_value * src._value) >> _fractionalBits;
	//  Le décalage à droite (>>) de 8 bits ramene le résultat à la bonne échelle.
	return (result);
}

Fixed	Fixed::operator/(const Fixed& src) const {

	Fixed	result;

	// Pour la division, il faut prendre en compte la partie fractionnaire
	result._value = ( (this->_value << _fractionalBits) / src._value );
	//  Le décalage à gauche (<<) de 8 bits ramene le résultat à la bonne échelle.
	return (result);
}

/*************************** OPERATEUR D'AFFECTATION  **************************/

Fixed& Fixed::operator=(const Fixed& src) {
	std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;

	if (this != &src)
		_value = src._value;

	return (*this);
}

/***************************** GETTER ET SETTER ******************************/

int	Fixed::getRawBits( void ) const {
	std::cout << GREEN << "getRawBits member function called" << RESET << std::endl;
	return (this->_value);
}

void Fixed::setRawBits( int const raw ) {

	std::cout << GREEN << "setRawBits called" << RESET << std::endl;
	this->_value = raw;
}

/***************** OPERATEURS D'INCREMENTATION ET DECREMENTATION ***************/

// prefix
Fixed&	Fixed::operator++(void) {
	this->_value += 1;
	return (*this);
} 

Fixed&	Fixed::operator--(void) {
	this->_value -= 1;
	return (*this);
}

// postfix
Fixed	Fixed::operator++(int) {
	Fixed	old(*this);
	this->_value += 1;
	return (old);
}

Fixed	Fixed::operator--(int) {
	Fixed	old(*this);
	this->_value -= 1;
	return (old);
}

/****************************** FONCTIONS MEMBRES ******************************/

float Fixed::toFloat( void ) const {
	return ( (float)this->_value / (1 << _fractionalBits) );
}

int Fixed::toInt( void ) const {
	return ( this->_value >> _fractionalBits );	
}

std::ostream& operator<<(std::ostream& os, const Fixed& src) {
	os << src.toFloat();
	return (os);
}

/************************** FONCTIONS STATICS MEMBRES **************************/

Fixed&		Fixed::min(Fixed& a, Fixed& b) {
	if (a._value > b._value)
		return (b);
	else
		return (a);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	if (a._value > b._value)
		return (b);
	else
		return (a);
}

Fixed&		Fixed::max(Fixed& a, Fixed& b) {
	if (a._value > b._value)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	if (a._value > b._value)
		return (a);
	else
		return (b);
}
