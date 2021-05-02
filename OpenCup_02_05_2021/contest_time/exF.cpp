// Made by Max Bronnikov
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;


struct lad{
    int idx;
    int prof;
    int sec_coord; // for sorting
};

bool operator<(lad lhs, lad rhs){
    return lhs.sec_coord < rhs.sec_coord;
}

int main(){
    int n1, n2;
    cin >> n1 >> n2;

    const int pang = 0;
    const int shou = 1;

    map<int, set<lad>> x_atacks; // key - x coord, value - lad, sorted by y
    map<int, set<lad>> y_atacks; // key - y coord, value - lad, sorted by x

    // pang lads
    for(int i = 0; i < n1; ++i){
        int lad_x, lad_y;
        cin >> lad_x >> lad_y;

        x_atacks[lad_x].insert({i, pang, lad_y});
        y_atacks[lad_y].insert({i, pang, lad_x});
    }

    // shou lads
    for(int i = 0; i < n2; ++i){
        int lad_x, lad_y;
        cin >> lad_x >> lad_y;

        x_atacks[lad_x].insert({i, shou, lad_y});
        y_atacks[lad_y].insert({i, shou, lad_x});
    }

    vector<int> pang_ans(n1, 0);
    vector<int> shou_ans(n2, 0);

    // search attacks by x lines
    for(const auto& [x, line] : x_atacks){
        bool is_first = true;

        lad last;
        for(const auto& l : line){
            if(is_first){
                last = l;
                is_first = false;

                continue;
            }

            if(l.prof != last.prof){
                if(l.prof){
                    shou_ans[l.idx] = 1;
                }else{
                    pang_ans[l.idx] = 1;
                }

                if(last.prof){
                    shou_ans[last.idx] = 1;
                }else{
                    pang_ans[last.idx] = 1;
                }
            }

            last = l;
        }
    }

    // search attacks by y lines
    for(const auto& [y, line] : y_atacks){
        bool is_first = true;

        lad last;
        for(const auto& l : line){
            if(is_first){
                last = l;
                is_first = false;

                continue;
            }

            if(l.prof != last.prof){
                if(l.prof){
                    shou_ans[l.idx] = 1;
                }else{
                    pang_ans[l.idx] = 1;
                }

                if(last.prof){
                    shou_ans[last.idx] = 1;
                }else{
                    pang_ans[last.idx] = 1;
                }
            }

            last = l;
        }
    }

    // print ans
    for(int i = 0; i < n1; ++i){
        cout << pang_ans[i];
    }
    cout << endl;

    for(int i = 0; i < n2; ++i){
        cout << shou_ans[i];
    }
    cout << endl;

    return 0;
}