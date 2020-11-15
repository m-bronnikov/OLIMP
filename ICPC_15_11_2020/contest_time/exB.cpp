// Made by Max Bronnikov
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(){
    string first_name, second_name;
    int first_stat = 0, second_stat = 0;

    map<pair<int, string>, int> union_team;
    map<pair<int, string>, int> on_place;

    vector<pair<int, string>> order;

    cin >> first_name;
    for(int i = 0; i < 5; ++i){
        string temp;
        cin >> temp;
        union_team[pair<int, string>(0, temp)] = 0;
        on_place[pair<int, string>(0, temp)] = 0;
        order.push_back(pair<int, string>(0, temp));
    }

    cin >> second_name;
    for(int i = 0; i < 5; ++i){
        string  temp;
        cin >> temp;
        union_team[pair<int, string>(1, temp)] = 0;
        on_place[pair<int, string>(1, temp)] = 0;
        order.push_back(pair<int, string>(1, temp));
    }

    int Q;
    cin >> Q;

    while(Q--){
        string team, movement;
        cin >> team; // empty inform
        cin >> team; // team name
        cin >> movement;
        if(movement == "scored"){
            int t;
            cin >> t;
            if(team == first_name){
                first_stat += t;
                second_stat -= t;
            }else{
                second_stat += t;
                first_stat -= t;
            }
        }else{
            string player1, player2;
            cin >> player1 >> movement >> player2;
            if(team == first_name){
                //if(union_team.count(player2)){}
                union_team[pair<int, string>(0, player1)] += first_stat - on_place[pair<int, string>(0, player1)]; 
                on_place.erase(pair<int, string>(0, player1));
                if(!union_team.count(pair<int, string>(0, player2))){
                    order.push_back(pair<int, string>(0, player2));
                }
                on_place[pair<int, string>(0, player2)] = first_stat;
            }else{
                //if(union_team.count(player2)){}
                union_team[pair<int, string>(1, player1)] += second_stat - on_place[pair<int, string>(1, player1)]; 
                on_place.erase(pair<int, string>(1, player1));
                if(!union_team.count(pair<int, string>(1, player2))){
                    order.push_back(pair<int, string>(1, player2));
                }
                on_place[pair<int, string>(1, player2)] = second_stat;
            }
        }
    }


    for(auto& it : on_place){
        if(it.first.first == 0){
            union_team[it.first] += first_stat - it.second; 
        }else{
            union_team[it.first] += second_stat - it.second;
        }
    }

    
    for(auto& kv : order){
        if(kv.first == 0){
            cout << kv.second << " (" << first_name << ") ";
        }else{
            cout << kv.second << " (" << second_name << ") ";
        }

        if(union_team[kv] > 0){
            cout << "+";
        }
        cout << union_team[kv] << endl;
    }

    return 0;
}