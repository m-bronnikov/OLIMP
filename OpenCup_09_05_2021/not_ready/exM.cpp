// Made by Max Bronnikov
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

// Time limit 42t =(

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unordered_map<char, char> second_transform = {
        {'b', 'p'},
        {'d', 'q'},
        {'o', 'o'},
        {'p', 'b'},
        {'q', 'd'},
        {'x', 'x'},
    };
    unordered_map<char, char> first_transform = {
        {'b', 'd'},
        {'d', 'b'},
        {'o', 'o'},
        {'p', 'q'},
        {'q', 'p'},
        {'x', 'x'},
    };

    string line;
    cin >> line;

    int first_count = 0;
    int second_count = 0;

    vector<int> idxs;

    // transform
    for(int i = 0; i < line.size(); ++i){
        if(line[i] == '('){
            idxs.push_back(i);
            continue;
        }
        if(line[i] == ')'){
            int l = idxs.back() + 1;
            int r = i;

            idxs.resize(idxs.size() - 1);

            reverse(begin(line) + l, begin(line) + r);

            for(int j = l; j < r; ++j){
                char c = line[j];

                if(c == '('){
                    continue;
                }
                if(c == '['){
                    continue;
                }
                if(c == ')'){
                    continue;
                }
                if(c == ']'){
                    continue;
                }

                line[j] = first_transform[c];
            }

            continue;
        }

        if(line[i] == '['){
            ++second_count;
            continue;
        }
        if(line[i] == ']'){
            --second_count;
            continue;
        }

        if(second_count & 1){
            line[i] = second_transform[line[i]];
        }
    }

    // write
    for(auto c : line){
        if(c == '('){
            continue;
        }
        if(c == '['){
            continue;
        }
        if(c == ')'){
            continue;
        }
        if(c == ']'){
            continue;
        }

        std::cout << c;
    }
    std::cout << endl;

    return 0;
}