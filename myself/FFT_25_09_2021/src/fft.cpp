// Made by Maksim Bronnikov
#include <vector> 
#include <cassert>
#include <algorithm>

#include "complex.h"

namespace {

bool is_pow_of_two(uint32_t num)
{
    return (num & (num - 1)) == 0;
}

void bit_reverse_reorder(std::vector<custom::complex> &x)
{
    auto const n = x.size();
    uint32_t j = 0u;

    // compite j = reverse(i) iterativelly
    for (uint32_t i = 1; i < n; ++i) {
        // add unit from left side (equialent to ++ from right side)
        auto bit = n >> 1; 
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        
        // swap only once
        if (i < j)
            std::swap(x[i], x[j]);
    }
}

} // namespace

namespace custom{

// simple fft with O(n logn) memory usage
std::vector<custom::complex> fft(const std::vector<custom::complex> &x, bool inverse = false){
    auto const n = x.size();
    assert(is_pow_of_two(n));

    if(n < 2)
    {
        return x;
    }

    // divide signal to odd and non-odd parts
    auto const half_n = n / 2;
    std::vector<custom::complex> lhs(half_n);
    std::vector<custom::complex> rhs(half_n);
    for(uint32_t i = 0, el = 0; i < half_n; ++i)
    {
        lhs[i] = x[el++];
        rhs[i] = x[el++];
    }

    // take DFT for w^2 of odd and not-odd parts
    auto const lft = fft(lhs, inverse);
    auto const rft = fft(rhs, inverse);

    // define ans
    std::vector<custom::complex> ans(n);

    // start point in exp(0*2pi/N) = 1, step of generator - exp(2pi/N)
    auto pi_x_2 = 2 * custom::pi;
    const custom::complex dw = inverse ? custom::exp({0, pi_x_2 / n}) : custom::exp({0, -pi_x_2 / n});
    custom::complex w = {1, 0};

    for(uint32_t k = 0; k < half_n; ++k, w *= dw)
    { 
        // compute DFT for w and -w
        ans[k]          = lft[k] + w*rft[k];
        ans[k + half_n] = lft[k] - w*rft[k];

        if(inverse)
        {
            ans[k] /= 2.0;
            ans[k + half_n] /= 2.0;
        }
    }

    return ans;
}

// optimized inplace fft without memory overheap (usage - O(n))
void inplace_fft(std::vector<custom::complex> &x, bool inverse = false){
    auto const n = x.size();
    assert(is_pow_of_two(n));

    if(n < 2)
        return;

    auto const half_n = n >> 1;
    constexpr auto const pi = custom::pi;

    // swap values for correct order
    bit_reverse_reorder(x);

    // inplace computation
    for(uint32_t arrs = half_n, step = 1; arrs > 0; arrs >>= 1, step <<= 1)
    {
        const custom::complex dw = inverse ? custom::exp({0, pi / step}) : custom::exp({0, -pi / step}); // pi / step = 2pi / len
        custom::complex w = {1.0, 0.0}; // e^0

        for(uint32_t k = 0; k < step; ++k, w *= dw){
            for(uint32_t a = 0; a < arrs; ++a){
                auto *array = &x[a * (step << 1)]; // a * (step << 1) = a * len

                // take DFT for w^2 of odd and not-odd parts
                auto const lhs = array[k];
                auto const rhs = array[k + step];

                // compute DFT for w and -w
                array[k]         = lhs + w*rhs;
                array[k + step]  = lhs - w*rhs;
            }
        }
    }

    if(not inverse)
        return;

    // for inverse DFT normalization is required
    auto const norm_coeff = 1.0 / n;
    for(auto& element : x)
        element *= norm_coeff;

    return;
}

} // namespace custom