// Made by Max Bronnikov
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <set>

using namespace std;


// define  bor
struct node;

using bor = map<char, node>;

struct node{
    set<int> counter;
    bor childs;
};



int main(){
    int n;
    cin >> n;

    bor prefix_bor, suffix_bor;
    string str;
    
    // build bors
    while(n--){
        cin >> str;

        bor* searcher = nullptr;

        // for pref
        searcher = &prefix_bor;
        for(int i = 0; i < str.size(); ++i){
            node* tmp_pos = &((*searcher)[str[i]]);
            tmp_pos->counter.emplace(n);
            
            searcher = &tmp_pos->childs;
        }

        // for postf
        searcher = &suffix_bor;
        for(int i = str.size() - 1; i >= 0; --i){
            node* tmp_pos = &((*searcher)[str[i]]);
            tmp_pos->counter.emplace(n);
            
            searcher = &tmp_pos->childs;
        }
    }

    cin >> n;
    set<int> nums;
    // do requests
    while(n--){
        nums.clear();
        
        cin >> str;

        bor* searcher = nullptr;
        node* last = nullptr;

        // for pref
        searcher = &prefix_bor;
        last = nullptr;
        for(int i = 0; i < str.size(); ++i){
            last = &((*searcher)[str[i]]);
            
            searcher = &last->childs;
        }

        nums.insert(begin(last->counter), end(last->counter));

        cin >> str;

        // for postf
        searcher = &suffix_bor;
        last = nullptr;
        for(int i = str.size() - 1; i >= 0; --i){
            last = &((*searcher)[str[i]]);
            
            searcher = &last->childs;
        }

        nums.insert(begin(last->counter), end(last->counter));

        cout << nums.size() << endl;
    }

    return 0;
}