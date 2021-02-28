#include <iostream>
#include <vector>

using namespace std;

int main(){
    const vector<int> ans = {1, 1, 2, 720, 768863313, 378780110, 828558729, 
            307323910, 233939875, 888030359, 821984089, 644056242, 527656359};

    int n;
    cin >> n;

    if(n > 12){
        cout << 0 << endl;
        return 0;
    }

    cout << ans[n] << endl;

    return 0;
}