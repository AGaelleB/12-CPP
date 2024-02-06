// public
Fixed::Fixed(void):_number(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(int const integer)
{
	std::cout << "Int constructor called\n";
	this->_number = integer << this->_fract;
}

Fixed::Fixed(float const flt)
{
	std::cout << "Float constructor called\n";
	this->_number  = (int)roundf(flt * (1 << this->_fract));
	std::cout << "flt: " << flt << " numb: " << this->_number << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called\n";
	this->_number = src.getRawBits();
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called\n";
	this->_number = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	return this->_number;
}

void	Fixed::setRawBits(int const raw)
{
	this->_number = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)this->_number / (1 << this->_fract);
}

int	Fixed::toInt(void) const
{
	return this->_number >> this->_fract;
}

std::ostream & operator<<(std::ostream & ost, Fixed const &rhs)
{
	ost << rhs.toFloat();
	return ost;
}

bool	Fixed::operator>(Fixed const & rhs) const
{
	return (this->_number > rhs._number);
}

bool	Fixed::operator<(Fixed const & rhs) const
{
	return (this->_number < rhs._number);
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	return (this->_number >= rhs._number);
}

bool	Fixed::operator<=(Fixed const & rhs) const
{
	return (this->_number <= rhs._number);
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	return (this->_number == rhs._number);
}

bool	Fixed::operator!=(Fixed const & rhs) const
{
	return (this->_number != rhs._number);
}

Fixed	Fixed::operator+(Fixed const & rhs) const
{
	Fixed	result;

	result.setRawBits(this->_number + rhs._number);
	return result;
}

Fixed	Fixed::operator-(Fixed const & rhs) const
{
	Fixed	result;

	result.setRawBits(this->_number - rhs._number);
	return result;
}

Fixed	Fixed::operator*(Fixed const & rhs) const
{
	Fixed	result;

	result.setRawBits((this->_number * rhs._number) >> this->_fract);
	return result;
}

Fixed	Fixed::operator/(Fixed const & rhs) const
{
	Fixed	result;

	result.setRawBits((this->_number << this->_fract) / rhs._number);
	return result;
}

// prefix
Fixed &	Fixed::operator++(void)
{
	this->_number += 1;
	return *this;
}

Fixed &	Fixed::operator--(void)
{
	this->_number -= 1;
	return *this;
}

// postfix
Fixed	Fixed::operator++(int)
{
	Fixed	old(*this);
	this->_number += 1;
	return old;
}

Fixed	Fixed::operator--(int)
{
	Fixed	old(*this);
	this->_number -= 1;
	return old;
}
