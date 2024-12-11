#include "Fixed.hpp"
#include <iostream>

const int Fixed::bits = 8;

Fixed::Fixed()
{
    this->_fixedNumber = 0;
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int num)
{
    this->_fixedNumber = num << bits;
}
Fixed::Fixed(const float num)
{
    // bitwise opeartor cannot be done with floats
    this->_fixedNumber = num * pow(2, 8);
}


Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& rhs)
{
    this->_fixedNumber = rhs._fixedNumber;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
    if (this == &rhs) // same address 
        return *this;
     std::cout << "Copy assignment operator called" << std::endl;
     this->_fixedNumber = rhs._fixedNumber;
     return *this;
}

int Fixed::getRawBits(void) const{ 
    // here  goes to logic
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedNumber >> bits); //divide
}

void    Fixed::setRawBits(int   const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedNumber = raw << bits; // multiply
}

float   Fixed::toFloat(void)    const
{
    float value = this->_fixedNumber >> bits;
    return (value);
}

int     Fixed::toInt(void)     const
{
    int value;

    value = this->_fixedNumber >> bits;
    return (value);
}
/*An overload of the insertion («) operator that inserts a floating-point representation
of the fixed-point number into the output stream object passed as parameter.*/
std::ostream& Fixed::operator<<(std::ostream& os, const Fixed& rhs)
{
    
}