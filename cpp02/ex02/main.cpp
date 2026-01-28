#include <iostream>
#include "Fixed.hpp"

int main(void) {
    Fixed a(10);
    Fixed b(20);
    Fixed const c(5.5f);
    Fixed const d(2);

    std::cout << "--- Comparison Operators ---" << std::endl;
    std::cout << "a: " << a << " | b: " << b << std::endl;
    std::cout << "a > b:  " << (a > b) << std::endl;
    std::cout << "a < b:  " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << std::endl;

    std::cout << "--- Arithmetic Operators ---" << std::endl;
    std::cout << "c: " << c << " | d: " << d << std::endl;
    std::cout << "c + d: " << (c + d) << std::endl;
    std::cout << "c - d: " << (c - d) << std::endl;
    std::cout << "c * d: " << (c * d) << std::endl;
    std::cout << "c / d: " << (c / d) << std::endl;
    std::cout << std::endl;

    std::cout << "--- Increment / Decrement ---" << std::endl;
    Fixed e(0);
    std::cout << "e initially: " << e << std::endl;
    std::cout << "++e:         " << ++e << std::endl;
    std::cout << "e now:       " << e << std::endl;
    std::cout << "e++:         " << e++ << std::endl;
    std::cout << "e now:       " << e << std::endl;
    std::cout << "--e:         " << --e << std::endl;
    std::cout << "e now:       " << e << std::endl;
    std::cout << "e--:         " << e-- << std::endl;
    std::cout << "e now:       " << e << std::endl;
    std::cout << std::endl;

    std::cout << "--- Min / Max Methods ---" << std::endl;
    std::cout << "min(a, b):   " << Fixed::min(a, b) << std::endl;
    std::cout << "max(a, b):   " << Fixed::max(a, b) << std::endl;
    std::cout << "min(const c, const d): " << Fixed::min(c, d) << std::endl;
    std::cout << "max(const c, const d): " << Fixed::max(c, d) << std::endl;

    return 0;
}