#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;
/*
typedef struct magic{
    int dist;
    int index;
    int another;
}magic;
*/

/*
bool operator<(const magic lhs, const magic rhs){
    if(lhs.another < lhs.dist && rhs.another < rhs.another){
        return lhs.another < rhs.another;
    }
    if(lhs.another < lhs.dist){
        return true;
    }
    if(rhs.another < rhs.dist){
        return false;
    }
    return lhs.dist < rhs.dist;
}
*/


int main(){
    int N;
    cin >> N;
    //map<int, int> antens;
    //map<int, int> robots;
    //vector<int> order;
    vector<int> a(N);
    vector<int> b(N);
    //vector<int> more(N, 0);
    //unordered_map<int, int> a(N);
    //unordered_map<int, int> b(N);
    vector<int> p(N, 0);
    //vector<magic> index(N);
    
    int x = 0;
    for(int i = 0; i < N; ++i){
        //a[i] = 0;
        cin >> a[i];
    }

    for(int i = 0; i < N; ++i){
        //b[i] = 0;
        cin >> b[i];
        // int dist = abs(b[i] - a[i]);
        x += abs(b[i] - a[i]);
        /*
        vector<int>::iterator it;
        if(a[i] < b[i]){
            it = upper_bound(a.begin(), a.end(), b[i] - dist);
        }else{
            it = lower_bound(a.begin(), a.end(), b[i] - dist);
        }
        for(int j = *it; abs(a[j] - b[i]) < dist; ++j){
            ++more[i];
        }
        */
    }

    cout << x << endl;
    
    for(int i = 0; i < N; ++i){  
       auto last = a.end();
       auto it = a.begin();
       auto jt = b.begin();

        for(int j = 0; j < N; ++j){
        /*
        while(true){
            auto temp = it;
            if(it->second < jt->second){
                ++temp;
            }else{
                temp = last;
            }
            if(temp != a.end()){
                if(abs(temp->second - jt->second) < abs(it->second - jt->second)){
                    ++it;
                    ++jt;
                    ++last;
                    continue;
                }
            }
            cout << ((jt->first) + 1) << ' ';

            a.erase(it);
            b.erase(jt);
            break;
       }
       */
            if(p[j]){
                continue;
            }

            if(b[j] > a[j]){
                int k = j+1;
                int dist = b[j] - a[j];
                for(; k < N && abs(a[k] - b[j]) < dist; ++k){
                    if(!p[k]){
                        break;
                    }
                }
                if(k < N && abs(a[k] - b[j]) < dist){
                    continue;
                }
            }else{
                int k = j - 1;
                int dist = a[j] - b[j];
                for(; k >= 0 && abs(a[k] - b[j]) <= dist; ++k){
                    if(!p[k]){
                        break;
                    }
                }
                if(k >= 0 && abs(a[k] - b[j]) <= dist){
                    continue;
                }
            }

            cout << j + 1 << ' ';
            ++p[j];
        }
    }

    cout << endl;
    return 0;
}
