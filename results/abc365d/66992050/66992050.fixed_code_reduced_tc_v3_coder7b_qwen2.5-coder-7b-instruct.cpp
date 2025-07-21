#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int N;
  string S;
  cin >> N >> S;
  vector<char> past(2);
  int ans = 0;
  for(int i = 0; i < N; ++i){
    char c = S[i];
    if(i == 0 || past[0] != c){
      ans++;
      past[1] = past[0];
      if(c == 'P') past[0] = 'S';
      else if(c == 'R') past[0] = 'P';
      else past[0] = 'R';
    }
  }
  cout << ans;
  return 0;
}