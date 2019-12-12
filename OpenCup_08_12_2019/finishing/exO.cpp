// Made by Max Bronnikov
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int main(){
    const pair<int, int> weight_sword(4, 0);
    const pair<int, int> weight_archery(5, 1);
    const pair<int, int> weight_weapon(2, 2);
    while(true){
        int M, G, S, A, T;
        cin >> M >> G >> S >> A >> T;
        if(!(M || G || S || A || T)){
            return 0;
        }
        M /= 25;
        G /= 50;
        // Init weight and cost objects
        int amount1 = M / weight_sword.first;
        int amount2 = min(M / weight_archery.first, G / weight_archery.second);
        int amount3 = min(M / weight_weapon.first, G / weight_weapon.second);
        int amount = amount1 + amount2 + amount3;
        if(!amount){
            cout << 0 << endl;
            continue;
        }

        vector<pair<int, int>> w(amount);
        set<pair<int, int>> possible_weight;
        vector<int> c(amount);
        for(int i = 0; i < amount1; ++i){
            w[i] = weight_sword;
            c[i] = S;
        }
        for(int i = amount1; i < amount2 + amount1; ++i){
            w[i] = weight_archery;
            c[i] = A;
        }
        for(int i = amount1 + amount2; i < amount; ++i){
            w[i] = weight_weapon;
            c[i] = T;
        }

        for(int i = 0; i <= M; ++i){
            for(int j = 0; j <= G; ++j){
                possible_weight.insert(pair<int, int>(i, j));
            }
        }
        //vector<vector<vector<int>>> 
           // dp(amount, vector<vector<int>>(M, vector<int>(G, 0))>;
        map<pair<int, int>, int> cur, prew;

        for(auto it = possible_weight.lower_bound(w[0]); it != possible_weight.end(); ++it){
            cur[*it] = c[0];
        }

        prew.swap(cur);

        for(int i = 1; i < amount; ++i){
            for(auto it = possible_weight.lower_bound(w[i]); it != possible_weight.end(); ++it){
                cur[*it] = max(prew[*it], prew[pair<int, int>(it->first - w[i].first, it->second - w[i].second)] + c[i]);
            }
            for(auto it = possible_weight.begin(); it != possible_weight.lower_bound(w[i]); ++it){
                cur[*it] = prew[*it];
            }
            prew.swap(cur);
        }
        auto ans = --prew.end();
        cout << ans->second << endl;
    }
}
