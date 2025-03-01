#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int value; 
    static const int fractionalBits = 8; 

public:
    Fixed();
    Fixed(const Fixed& fixed); 
    Fixed(const int value); 
    Fixed(const float value);


    float toFloat() const;
    int toInt() const; 
    int getRawBits() const; 
    void setRawBits(int const raw); 

    Fixed& operator=(const Fixed& fixed); 
    ~Fixed(); 
};

std::ostream& operator<<(std::ostream& os , Fixed const &fixed);

#endif