// Made by Maksim Bronnikov
#include "complex.h"

namespace custom{


complex operator*(const complex& lhs, const complex& rhs)
{
    // (r1 + j i1) * (r2 + j i2) = (r1*r2 - i1*i2) + j*(r1*i2 + r2*i1)
    return {lhs.re*rhs.re - lhs.im*rhs.im, lhs.re*rhs.im + lhs.im*rhs.re};
}

complex operator+(const complex& lhs, const complex& rhs)
{
    return {lhs.re + rhs.re, lhs.im + rhs.im};
}

complex operator-(const complex &rhs)
{
    return {-rhs.re, -rhs.im};
}

complex operator-(const complex &lhs, const complex &rhs)
{
    return {lhs.re - rhs.re, lhs.im - rhs.im};
}

complex exp(const complex& arg)
{
    // exp(x + jy) = exp(x)*exp(j*y)
    double modulo = std::exp(arg.re);
    
    // Euler formula: exp(j*w) = cos(w) + j*sin(w)
    return {modulo*std::cos(arg.im), modulo*std::sin(arg.im)};
}

complex &complex::operator*=(const complex& rhs)
{
    double tmp_re = this->re*rhs.re - this->im*rhs.im;
    this->im = this->re*rhs.im + this->im*rhs.re;
    this->re = tmp_re;
    return *this;
}

complex &complex::operator+=(const complex& rhs)
{
    re += rhs.re;
    im += rhs.im;
    return *this;
}

complex &complex::operator*=(double rhs)
{
    re *= rhs;
    im *= rhs;
    return *this;
}

complex &complex::operator/=(double rhs)
{
    re /= rhs;
    im /= rhs;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const custom::complex &num)
{
    bool re_exist = false;
    if(std::abs(num.re) > std::numeric_limits<double>::epsilon()){
        os << num.re;
        re_exist = true;
    }

    if(std::abs(num.im) < std::numeric_limits<double>::epsilon()){
        if(not re_exist)
        {
            os << 0.0;
        }

        return os;
    }

    if(num.im < 0.0){
        os << '-';
    }
    else{
        os << '+';
    }

    os << 'j' << std::abs(num.im);

    return os;
}

}