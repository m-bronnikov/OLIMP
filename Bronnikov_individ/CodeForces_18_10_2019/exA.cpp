#include <iostream>
#include <set>
#include <inttypes.h>

int main(){
    uint32_t N, c;
    std::cin >> N;
    std::set<uint32_t> st;
    for(uint32_t i = 0; i < N; ++i){
        std::cin >> c;
        st.insert(c);
    }
    c = *st.begin();
    for(uint32_t i = 0; i < N; ++i){
        if(!st.count(c++)){
            std::cout << "Scammed" << std::endl;
            return 0;
        }
    }
    std::cout << "Deck looks good" << std::endl;
    return 0;
}