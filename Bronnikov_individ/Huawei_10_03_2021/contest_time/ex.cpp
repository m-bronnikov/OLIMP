#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

#define IMPOSSIBLE_IF(ARG)   \
    if ((ARG))                       \
    {                                \
        cout << "Impossible" << endl; \
        return 0; \
    }

// note: search a -> b, b -> c, c -> d, d -> b
int search_circles(unordered_map<char, char>& vocab){
    set<char> circle;

    char from = begin(vocab)->first;
    while(not circle.count(from)){
        // if secuence is not circle - return size of sequence
        if(not vocab.count(from)){
            return circle.size();
        }
        
        circle.insert(from);
        
        char to = vocab[from];

        vocab.erase(from);

        from = to;
    }

    // for resolve circle we need 1 additional operation with free char
    return circle.size() + 1;
}

int main(){
    const int alphabet_count = 26; // engleesh
    unordered_map<char, char> vocab;
    string first, second;
    int count = 0;

    cin >> first >> second;

    // first check: lens are equal
    IMPOSSIBLE_IF(first.size() != second.size());

    // fill map with pairs
    for(int i = 0; i < first.size(); ++i){
        // second check: transform is unique (f(a) = b, f(a) = c <=> c = b)
        IMPOSSIBLE_IF(vocab.count(first[i]) && vocab[first[i]] != second[i]);

        vocab[first[i]] = second[i];
    }

    // remove all pairs: a->b, where a == b, because it zero count transformation:
    for(char c = 'a'; c <= 'z'; ++c){
        if(vocab.count(c) && vocab[c] == c){
            vocab.erase(c);
        }
    }

    // for cases. where a -> b, b -> a, c -> b most simple and fast way is: transform c -> a first.
    {
        unordered_map<char, char> value_key;
        for(const auto& [key, value] : vocab){
            value_key[value] = key;
        }

        count += vocab.size() - value_key.size();

        // rewrite map only with unique pairs by key and value
        vocab.clear();

        bool diffrence = false;
        
        for(const auto& [value, key] : value_key){
            diffrence |= (value != key);
            vocab[key] = value;
        }

        // third check: exist free char to resolve circles if exist:
        IMPOSSIBLE_IF(vocab.size() >= alphabet_count && diffrence);
    }

    while(vocab.size()){
        count += search_circles(vocab);
    }

    cout << count << endl;

    return 0;
}