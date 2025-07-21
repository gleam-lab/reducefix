#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;
  string S;
  cin >> N >> S;
  
  // Initialize past character to something that forces first move to count
  char past = 'N';  // Will only match nothing, so first move will always be counted
  int ans = 0;
  
  for(char c : S){
    if(c == 'P'){
      if(past != 'S'){
        ans++;
        past = 'S';
      }
    }
    else if(c == 'R'){
      if(past != 'P'){
        ans++;
        past = 'P';
      }
    }
    else if(c == 'S'){ // S beats R
      if(past != 'R'){
        ans++;
        past = 'R';
      }
    }
  }
  
  cout << ans;
  return 0;
}