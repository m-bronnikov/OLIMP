// Made by Maksim Bronnikov
#ifndef __COMPLEX_NUMBER__
#define __COMPLEX_NUMBER__

#include <cmath>
#include <limits>
#include <ostream>

namespace custom{

constexpr const double pi = M_PI;

struct complex{
// fields:
    double re = 0;
    double im = 0;

// operators:
    complex &operator*=(const complex& rhs);
    complex &operator+=(const complex& rhs);
    complex &operator*=(const double rhs);
    complex &operator/=(const double rhs);
};

// freind operators
complex operator*(const complex& lhs, const complex& rhs);
complex operator+(const complex& lhs, const complex& rhs);
complex operator-(const complex &rhs);
complex operator-(const complex &lhs, const complex &rhs);
complex exp(const complex &arg);

// output operator
std::ostream &operator<<(std::ostream &os, const custom::complex &num);

} // namespace custom

#endif // __COMPLEX_NUMBER__