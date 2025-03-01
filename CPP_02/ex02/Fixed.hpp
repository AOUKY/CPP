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

    Fixed operator+(const Fixed& rhs) const;
    Fixed operator-(const Fixed& rhs) const;
    Fixed operator*(const Fixed& rhs) const;
    Fixed operator/(const Fixed& rhs) const;    

    bool operator>(const Fixed& rhs) const;
    bool operator<(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;    

    Fixed& operator++(); 
    Fixed operator++(int); 
    Fixed& operator--(); 
    Fixed operator--(int); 

    Fixed& operator=(const Fixed& fixed); 
    ~Fixed(); 

    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os , Fixed const &fixed);

#endif