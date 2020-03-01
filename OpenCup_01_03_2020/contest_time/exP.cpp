// Made by Bronnikov Max
#include <set>
#include <iostream>
#include <string>

using namespace std;

int main(){
    string alfabet;
    string example;
    cin >> alfabet;
    cin >> example;
    set<string> storage = {example};
    // deletes:
    for(int i = 0; i < example.size(); ++i){
        string first = example.substr(0, i), second = example.substr(i + 1), try_new;
        // delete:
        try_new = first + second;
        if(storage.find(try_new) == storage.end()){
            storage.insert(try_new);
        }
        // insert:
        second = example.substr(i);
        for(int j = 0; j < alfabet.size(); ++j){
            try_new = first;
            try_new.push_back(alfabet[j]);
            try_new += second;
            if(storage.find(try_new) == storage.end()){
                storage.insert(try_new);
            }
        }
        // change:
        try_new = example;
        for(int j = 0; j < alfabet.size(); ++j){
            try_new[i] = alfabet[j];
            if(storage.find(try_new) == storage.end()){
                storage.insert(try_new);
            }
        }
    }
    storage.erase(example);
    example.push_back(alfabet[0]);
    for(int j = 0; j < alfabet.size(); ++j){
        example.back() = alfabet[j];
        if(storage.find(example) == storage.end()){
            storage.insert(example);
        }
    }

    for(auto print : storage){
        cout << print << endl;
    }
    return 0;
}