// Made by Max Bronnikov
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>


using namespace std;


int main(){
    int N;
    cin >> N;

    vector<string> img1(N);
    vector<string> img2(N);

    for(int i = 0; i < N; ++i){
        cin >> img1[i];
    }

    for(int i = 0; i < N; ++i){
        cin >> img2[i];
    }

    bool plag = false;
    // 1:
    plag = true;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(img1[i][j] != img2[i][j]){
                plag = false;
                break;
            }
        }
        if(!plag){
            break;
        }
    }

    if(plag){
        cout << "YES" << endl;
        return 0;
    }

    // 2:
    plag = true;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(img1[i][j] != img2[i][N - j - 1]){
                plag = false;
                break;
            }
        }
        if(!plag){
            break;
        }
    }

    if(plag){
        cout << "YES" << endl;
        return 0;
    }

    // 3:
    plag = true;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(img1[i][j] != img2[N - i - 1][j]){
                plag = false;
                break;
            }
        }
        if(!plag){
            break;
        }
    }

    if(plag){
        cout << "YES" << endl;
        return 0;
    }

    // 4:
    plag = true;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(img1[i][j] != img2[N - i - 1][N - j - 1]){
                plag = false;
                break;
            }
        }
        if(!plag){
            break;
        }
    }

    if(plag){
        cout << "YES" << endl;
        return 0;
    }

    // 5:
    plag = true;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(img1[i][j] != img2[j][i]){
                plag = false;
                break;
            }
        }
        if(!plag){
            break;
        }
    }

    if(plag){
        cout << "YES" << endl;
        return 0;
    }

    // 6:
    plag = true;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(img1[i][j] != img2[N - j - 1][N - i - 1]){
                plag = false;
                break;
            }
        }
        if(!plag){
            break;
        }
    }

    if(plag){
        cout << "YES" << endl;
        return 0;
    }

    // 7:
    plag = true;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(img1[i][j] != img2[N - j - 1][i]){
                plag = false;
                break;
            }
        }
        if(!plag){
            break;
        }
    }

    if(plag){
        cout << "YES" << endl;
        return 0;
    }

    // 8:
    plag = true;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(img1[i][j] != img2[j][N - i - 1]){
                plag = false;
                break;
            }
        }
        if(!plag){
            break;
        }
    }

    if(plag){
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;
    return 0;
}