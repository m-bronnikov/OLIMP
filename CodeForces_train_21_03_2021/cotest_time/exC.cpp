#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    std::cin >> n;

    vector<vector<int>> nbhrs(n + 1);

    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        nbhrs[a].push_back(b);
        nbhrs[b].push_back(a);
    }

    int counter = 0;
    for(int i = 2; i <= n; ++i){
        if(nbhrs[i].size() == 1){
            if(nbhrs[i][0] != 1 && nbhrs[nbhrs[i][0]].size() == 2){
                ++counter;
            }
        }
    }

    cout << counter << endl;

    return 0;
}