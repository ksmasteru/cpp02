#pragma once
#include <iostream>

class Fixed{
    private:
        int _fixedNumber;
        const static int bits;

    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float num);//!!
        ~Fixed();
        Fixed(const Fixed& rhs);
        Fixed& operator= (const Fixed& rhs);  
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void)   const;
        int     toInt(void)     const;
};
/*An overload of the insertion («) operator that inserts a floating-point representation
of the fixed-point number into the output stream object passed as parameter.*/
std::ostream& operator<< (std::ostream& os, const Fixed& rhs);


/*to be able to declare an overload function inside the class the LHS operand should an instance of
the class which is not the case for << operator : LHS operand is ostream object.*/