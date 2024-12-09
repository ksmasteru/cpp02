#pragma once

class Fixed{
    private:
        int _fixedNumber;
        const static int bits;

    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& rhs);
        Fixed& operator= (const Fixed& rhs);  
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};
