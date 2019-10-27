#ifndef _PRIME_NUMS_
#define _PRIME_NUMS_

#include <vector>
#include <algorithm>

bool isPrime(unsigned val);
void erot_soive_num(unsigned lim, std::vector<unsigned>& result);
void erot_soive_bool(unsigned lim, std::vector<bool>& result);
void simple_factors_of_num(unsigned num, std::vector<unsigned>& result);


bool isPrime(unsigned val){
    for(unsigned i = 2; i * i < val; ++i){
        if(!(val % i)){
            return false;
        }
    }
    return true;
}

// get updated soive with first prime div
void erot_soive_num(unsigned lim, std::vector<unsigned>& result){
    result.assign(lim + 1, 0);
    result[0] = result[1] = 1;
    for(unsigned i = 2; i*i <= lim; ++i){
        if(result[i]){
            continue;
        }
        for(unsigned j = i*i; j <= lim; j+=i){
            result[j] = i;
        }
    }
}

// standart soive of erot (0- prime, 1 - not prime)
void erot_soive_bool(unsigned lim, std::vector<bool>& result){
    result.assign(lim + 1, 0);
    result[0] = result[1] = true;
    for(unsigned i = 2; i*i <= lim; ++i){
        if(result[i]){
            continue;
        }
        for(unsigned j = i*i; j <= lim; j+=i){
            result[j] = true;
        }
    }
}

// get factors of num:

void simple_factors_of_num(unsigned num, std::vector<unsigned>& result){
    std::vector<unsigned> divs;
    erot_soive_num(num, divs);
    result.clear();
    while(divs[num]){
        result.push_back(divs[num]);
        num /= divs[num];
    }
    result.push_back(num);
    std::sort(result.begin(), result.end());
}

#endif // _PRIME_NUMS_
