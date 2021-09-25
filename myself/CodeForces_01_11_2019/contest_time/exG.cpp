// Made by Max Bronnikov

#include <iostream>
#include <vector>

using namespace std;

int min_of_three(int a1, int a2, int a3){
  if(a1 > a2){
    if(a1 > a3){
      return a1;
    }else{
      return a3;
    }
  }else{
    if(a2 > a3){
      return a2;
    }else{
      return a3;
    }
  }
}

int main(){
  int n, m; // 4 байта
  cin >> n >> m;
  vector<int> path(n*m);
  vector<int> gold(n*m, 0);
  for(int i = 0; i < n * m; ++i){
      cin >> path[i];
      gold[i] = path[i];  
  }

  for(int i = 1; i < m; ++i){
      gold[i] += gold[i-1];
  }
  for(int j = 1; j < n; ++j){
      gold[m * j] += gold[m * (j - 1)];
  }

  for(int i = 1; i < n; ++i){
      for(int j = 1; j < m; ++j){
          gold[i*m + j] += min_of_three(gold[i*m + j - 1], gold[(i - 1)*m + j], gold[(i - 1)*m + j - 1]);
      }
  }
  cout << gold[(n-1)*m + m - 1] << endl;
  return 0;
} 