#include <iostream>

#include <vector>
#include <string>
#include <array>


template <int N>
class Generator{
public:
    constexpr Generator(int k) : valid(true), K(k)
    {
        reset(); 
    }

    bool is_valid() const { return valid; }

    void reset()
    {
        for(int i = 0; i < K; ++i)
        {
            state[i] = i;
        }

        valid = true;
    }

    int next() 
    {
        const int ans = state_to_num();

        for(int i = 0; i < K; ++i)
        {
            int idx = K - i - 1;
            if(++state[idx] >= N - i)
            {
                continue;
            }

            for(int j = idx + 1; j < K; ++j)
            {
                state[j] = state[j - 1] + 1;
            }

            return ans;
        }

        valid = false;
        return ans;
    }

private:
    int state_to_num() const
    {
        int num = 0;

        for(int i = 0; i < K; ++i)
        {
            num |= (1 << state[i]);
        }

        return num;
    }

private:
    bool valid;
    const int K;
    std::array<int, N> state{};
};


class Solution {
private:

public:
    std::vector<std::string> readBinaryWatch(int turned_on) {
        std::vector<std::string> ans;

        for(int i = 0; i <= top_leds; ++i)
        {
            if(i > turned_on) break;
            if(turned_on - i > down_leds) continue;

            Generator<top_leds> top_gen(i);
            while(top_gen.is_valid())
            {
                int hours = top_gen.next();
                if(hours > 11)
                {
                    continue;
                }

                Generator<down_leds> down_gen(turned_on - i);
                while (down_gen.is_valid())
                {
                    int minuts = down_gen.next();
                    if(minuts > 59)
                    {
                        continue;
                    }

                    std::string time = std::to_string(hours);
                    time.push_back(':');
                    if(minuts < 10)
                    {
                        time.push_back('0');
                    }
                    time += std::to_string(minuts);

                    ans.push_back(std::move(time));
                }
                
            }
        }

        return ans;
    }

private:
    static constexpr int top_leds = 4;
    static constexpr int down_leds = 6;
};


int main()
{
    auto result = Solution().readBinaryWatch(4);
    std::cout << result.size() << std::endl;

    for(auto& str : result)
    {
        std::cout << str << std::endl;
    }

    return 0;
}