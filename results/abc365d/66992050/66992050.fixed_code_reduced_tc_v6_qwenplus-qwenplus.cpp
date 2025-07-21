#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;
  string S;
  cin >> N >> S;
  
  // Initialize past as a neutral value that doesn't match any of R/S/P
  char past = 'N';
  int ans = 0;
  
  for(char c : S){
    if(c == 'R'){
      if(past != 'R'){
        ans++;
        past = 'R';
      }
    } else if(c == 'S'){
      if(past != 'S'){
        ans++;
        past = 'S';
      }
    } else if(c == 'P'){
      if(past != 'P'){
        ans++;
        past = 'P';
      }
    }
  }
  
  cout << ans;
  return 0;
}