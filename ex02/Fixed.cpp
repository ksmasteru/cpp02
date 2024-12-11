#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::bits = 8;

Fixed::Fixed()
{
    this->_fixedNumber = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedNumber = num << bits;
}

Fixed::Fixed(const float num)
{
    // bitwise opeartor cannot be done with floats
    std::cout << "float constructor called" << std::endl;
    this->_fixedNumber = num * (2 << (bits - 1));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& rhs)
{
    std::cout << "copy constructor called" << std::endl;
    this->_fixedNumber = rhs._fixedNumber;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
    if (this == &rhs) // same address 
        return *this;
     std::cout << "Copy assignment operator called" << std::endl;
     this->_fixedNumber = rhs._fixedNumber;
     return *this;
}

double Fixed::getRawBits(void) const{ 
    // here  goes to logic
    //std::cout << "getRawBits member function called" << std::endl;
    double divide_value = 2 << (bits - 1); 
    return ((double) this->_fixedNumber / divide_value); //divide
}

void    Fixed::setRawBits(int   const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedNumber = raw << bits; // multiply
}

float   Fixed::toFloat(void)    const
{
    /*• A member function float toFloat( void ) const;
        that converts the fixed-point value to a floating-point value.*/
    double divide_value = 2 << (bits - 1); 
    float value = this->_fixedNumber / divide_value;
    return (value);
}

int     Fixed::toInt(void)     const
{
    int value;

    value = this->_fixedNumber >> bits;
    return (value);
}

std::ostream& operator<<(std::ostream& os, const Fixed& rhs)
{
    os << rhs.getRawBits();
    return (os);
}

bool Fixed::operator< (const Fixed& rhs)
{
     // bits cannot be changed : this points to LHS
     if (this->_fixedNumber < rhs._fixedNumber)
        return (true);
    return (false);
}

bool Fixed::operator> (const Fixed& rhs)
{
     // bits cannot be changed : this points to LHS
    if (this->_fixedNumber > rhs._fixedNumber)
        return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed& rhs)
{
    if (this->_fixedNumber >= rhs._fixedNumber)
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed& rhs)
{
    if (this->_fixedNumber <= rhs._fixedNumber)
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed& rhs)
{
    if (this->_fixedNumber == rhs._fixedNumber)
        return (true);
    return (false);
}

bool Fixed::operator!=(const Fixed& rhs)
{
    if (this->_fixedNumber != rhs._fixedNumber)
        return (true);
    return (false);
}