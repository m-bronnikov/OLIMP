#include <iostream>
#include <map>

using namespace std;

int main()
{
    int N;

    cin >> N;

    map<int, int> cH;

    int maxH = 0;
    int currentH = 0;

    for(int i = 0; i < N; ++i){
        int temp;
        cin >> temp;
        if(temp > currentH){
            currentH = temp;
            cH[temp] = i;
        }else if(temp < currentH){
            auto beg = cH.upper_bound(temp);

            
            for(auto it = beg; it != cH.end(); ++it){
                if(it->first > maxH){
                    int len = i - it->second;
                    if(len >= maxH){
                        maxH = len > it->first ? it->first : len;
                    }
                }
            }

            int upddate_i = beg->second;

            cH.erase(beg, cH.end());


            if(!cH.count(temp)){
                cH[temp] = upddate_i;
            }

            currentH = temp;
        }
    }

    {
        auto beg = cH.begin();
        for(auto it = beg; it != cH.end(); ++it){
            if(it->first > maxH){
                int len = N - it->second;
                if(len >= maxH){
                    maxH = len > it->first ? it->first : len;
                }
            }
        }
    }

    std::cout << maxH << std::endl;

    return 0;
}