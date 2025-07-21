#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int N;
  string S;
  cin >> N >> S;
  char past = 'N';
  int ans = 0;
  for(char c:S){
    if(c=='P'){
      if(!(past=='S')){
        ans++;
        past = 'S';
      } 
      else{
        past = 'P';
      }
    }
    if(c=='R'){
      if(!(past=='P')){
        ans++;
        past = 'P';
      } 
      else{
        past = 'R';
      }
    }
    if(c=='S'){
      if(!(past=='R')){
        ans++;
        past = 'R';
      } 
      else{
        past = 'S';
      }
    }
  }
  cout << ans;
  return 0;
}
