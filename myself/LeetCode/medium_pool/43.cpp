#include <iostream>
#include <cassert>

#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

template <class FloatT>
constexpr FloatT pi() { return std::atan(1.0) * 4.0; }

namespace cmplx
{

template <class FloatT = float>
struct complex
{
    // ctors
    explicit complex() = default;
    complex(FloatT r) : re(r), im(0) {} 
    complex(FloatT r, FloatT i) : re(r), im(i) {}

    // unary operator
    complex operator-() const { return complex(-re, -im); }

    // complex argument operators
    complex operator+(complex rhs) const { return complex(re + rhs.re, im + rhs.im); }
    complex operator-(complex rhs) const { return complex(re - rhs.re, im - rhs.im); }
    complex operator*(complex rhs) const { return complex(re * rhs.re - im * rhs.im, re * rhs.im + im * rhs.re); }

    complex operator+=(complex rhs) { return *this = *this + rhs; }
    complex operator-=(complex rhs) { return *this = *this - rhs; }
    complex operator*=(complex rhs) { return *this = *this * rhs; }

    // real argument operators
    complex operator+(FloatT rhs) const { return complex(re + rhs, im); }
    complex operator-(FloatT rhs) const { return complex(re - rhs, im); }
    complex operator*(FloatT rhs) const { return complex(re * rhs, im * rhs); }
    complex operator/(FloatT rhs) const { return complex(re / rhs, im / rhs); }

    complex operator+=(FloatT rhs) { return *this = *this + rhs; }
    complex operator-=(FloatT rhs) { return *this = *this - rhs; }
    complex operator*=(FloatT rhs) { return *this = *this * rhs; }
    complex operator/=(FloatT rhs) { return *this = *this / rhs; }

    // value representation
    FloatT re;
    FloatT im;
};

// Eiler formula
template<class FloatT>
complex<FloatT> exp(complex<FloatT> p) { return complex<FloatT>(std::cos(p.im), std::sin(p.im)) * std::exp(p.re);  }

}

namespace fft
{

using namespace cmplx;

bool is_power_of_two(size_t val) { return (val & (val - 1)) == 0; }

template <class T>
void batterfly_permutate(std::vector<T>& arr)
{
    assert(is_power_of_two(arr.size()));

    size_t reversed_idx = 0;
    for(size_t idx = 1; idx < arr.size(); ++idx)
    {
        // reversed increment
        {
            size_t current_bit = arr.size();
            do {
                current_bit >>= 1;
                reversed_idx ^= current_bit;
            } while((reversed_idx & current_bit) == 0);
        }

        // swap if swap not done yet (if condition prevents double swap of same elements)
        if(reversed_idx < idx)
        {
            std::swap(arr[idx], arr[reversed_idx]);
        }
    }
}

template <bool inverse>
void fft_inplace(std::vector<complex<float>>& signal)
{
    assert(is_power_of_two(signal.size()));
    const size_t N = signal.size();

    // batterfly permutation is made to provide correct data order after fft
    batterfly_permutate(signal);

    for(size_t segments = N >> 1, dist = 1; segments > 0; segments >>= 1, dist <<= 1) {
        // exp(-j * 2 * pi / N) for common, exp(j * 2 * pi / N) for inverse
        const complex<float> dw = inverse ? exp(complex<float>(0, pi<float>() / dist)) : exp(complex<float>(0, -pi<float>() / dist));

        for(size_t seg = 0; seg < segments; ++seg) {
            complex<float> w = 1.0; // exp(-j * 2 * pi * 0 / N)

            for(size_t k = 0; k < dist; ++k, w *= dw) {
                const size_t i = seg * (dist << 1) + k;

                // take DFT for w^2 of odd and not-odd parts
                const complex<float> lhs = signal[i];
                const complex<float> rhs = w * signal[i + dist];

                signal[i] = lhs + rhs;
                signal[i + dist] = lhs - rhs;
            }
        }
    }

    // normalization is not required for common fft
    if constexpr (!inverse) {
        return;
    }

    // normalize
    const float coeff = 1.f / N;
    for(size_t i = 0; i < N; ++i) {
        signal[i] *= coeff;
    }
}

}

class Solution {
private:
    static size_t next_pow2(size_t v)
    {
        --v;
        v |= v >> 1;
        v |= v >> 2;
        v |= v >> 4;
        v |= v >> 8;
        v |= v >> 16;
        return ++v;
    }

public:
    std::string multiply(const std::string& num1, const std::string& num2) {
        std::vector<cmplx::complex<float>> vec1(num1.size());
        std::vector<cmplx::complex<float>> vec2(num2.size());

        for(size_t i = 0; i < num1.size(); ++i) {
            vec1[num1.size() - i - 1] = static_cast<float>(num1[i] - '0');
        }

        for(size_t i = 0; i < num2.size(); ++i) {
            vec2[num2.size() - i - 1] = static_cast<float>(num2[i] - '0');
        }

        const size_t size = next_pow2(num1.size() + num2.size());
        vec1.resize(size);
        vec2.resize(size);

        fft::fft_inplace<false>(vec1);
        fft::fft_inplace<false>(vec2);

        for(size_t i = 0; i < vec1.size(); ++i) {
            vec1[i] *= vec2[i];
        }
        
        fft::fft_inplace<true>(vec1);

        std::string s;

        uint32_t to_add = 0;
        for(int i = 0; i < vec1.size(); ++i) {
            uint32_t val = static_cast<uint32_t>(round(vec1[i].re)) + to_add;
            uint32_t div = val / 10;

            s.push_back(static_cast<char>(val - div * 10) + '0');
            to_add = div;
        }

        while(to_add) {
            uint32_t div = to_add / 10;
            s.push_back(static_cast<char>(to_add - div * 10) + '0');
            to_add = div;
        }

        while(!s.empty() && s.back() == '0') {
            s.pop_back();
        }
        std::reverse(begin(s), end(s));

        return s.empty() ? "0" : s;
    }
};

int main()
{
    std::cout << Solution().multiply("123456789", "987654321") << std::endl;

    return 0;
}