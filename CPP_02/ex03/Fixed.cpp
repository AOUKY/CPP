# include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->value = (value << fractionalBits);
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	this->value = roundf((value * (1 << fractionalBits)));
}

int Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return value;
}

float Fixed::toFloat() const
{
	return (float)value / (1 << fractionalBits);
}

int Fixed::toInt() const
{
	return (value >> fractionalBits);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if(this != &fixed)
	{
		this->value = fixed.value;
	}
	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return os;
}


Fixed Fixed::operator+(const Fixed& fixed) const 
{
  return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed& fixed) const 
{
  return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed& fixed) const 
{
  return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed& fixed) const 
{
  return Fixed(this->toFloat() / fixed.toFloat());
}


bool Fixed::operator>(const Fixed& fixed) const 
{
  return this->value > fixed.value;
}

bool Fixed::operator<(const Fixed& fixed) const 
{
  return this->value < fixed.value;
}

bool Fixed::operator>=(const Fixed& fixed) const 
{
  return this->value >= fixed.value;
}

bool Fixed::operator<=(const Fixed& fixed) const 
{
  return this->value <= fixed.value;
}

bool Fixed::operator==(const Fixed& fixed) const 
{
  return this->value == fixed.value;
}

bool Fixed::operator!=(const Fixed& fixed) const 
{
  return this->value != fixed.value;
}


Fixed& Fixed::operator++() 
{
  value += 1 ; 
  return *this;
}

Fixed Fixed::operator++(int) 
{
  Fixed temp(*this); 
  value += 1; 
  return temp; 
}

Fixed& Fixed::operator--() 
{
  value -= 1 ; 
  return *this;
}

Fixed Fixed::operator--(int) 
{
  Fixed temp(*this); 
  value -= 1; 
  return temp; 
}


Fixed& Fixed::min(Fixed& a, Fixed& b) 
{
	if(a < b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) 
{
 	if(a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) 
{
	if(a > b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) 
{
	if(a > b)
		return a;
	return b;
}
