#pragma once

class Fixed{
    private:
        int _fixedNumber;
        const static int bits;

    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        ~Fixed();
        Fixed(const Fixed& rhs);
        Fixed& operator= (const Fixed& rhs);  
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void)   const;
        int     toInt(void)     const;
};

/*A member function int toInt( void ) const;
that converts the fixed-point value to an integer value.*/