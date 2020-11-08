#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct group{
    group(vector<long long>& persons) : t(0), guys(persons) {}

    void send_msg(int person){
        ++t;
        ++storage[person];
    }

    void in_person(int person){
        storage[person] = t;
    }

    void out_person(int person){
        guys[person] += t - storage[person];
        storage.erase(person);
    }

    ~group(){
        for(auto& [key, value] : storage){
            guys[key] += t - value;
        }
    }
    
    int t;
    map<int, long long> storage;
    vector<long long>& guys;
};

int main(){
    int n, m, s;
    cin >> n >> m >> s;
    vector<long long> persons(m, 0);
    {
        vector<group> groups(n, persons);
        while(s--){
            int t, x, y;
            cin >> t >> x >> y;
            --x; --y;

            switch (t)
            {
            case 1:
            {
                groups[y].in_person(x);
                break;
            }
            case 2:
            {
                groups[y].out_person(x);
                break;
            }
            case 3:
            {
                groups[y].send_msg(x);
                break;
            }
            default:
                break;
            }
        }
    }

    for(long long& num : persons){
        cout << num << endl;
    }

    return 0;
}