#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// New in ex01: Constructor that converts an integer to a fixed-point value
Fixed::Fixed(const int intValue) {
    std::cout << "Int constructor called" << std::endl;
    this->value = intValue << fractionalBits;
}

// New in ex01: Constructor that converts a float to a fixed-point value
Fixed::Fixed(const float floatValue) {
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(floatValue * (1 << fractionalBits));
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->value = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw) {
    this->value = raw;
}

// New in ex01: Converts the fixed-point value to a floating-point value
float Fixed::toFloat(void) const {
    return (float)this->value / (1 << fractionalBits);
}

// New in ex01: Converts the fixed-point value to an integer value
int Fixed::toInt(void) const {
    return this->value >> fractionalBits;
}

// New in ex01: Overload of insertion operator to print the fixed-point as a float
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}