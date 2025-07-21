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
    if(past == 'N') {
      past = c;
      continue;
    }
    if((c=='R' && past=='S') || (c=='P' && past=='R') || (c=='S' && past=='P')) {
      ans++;
      past = c;
    } else {
      past = (past == 'R') ? 'P' : ((past == 'P') ? 'S' : 'R');
    }
  }
  cout << ans;
  return 0;
}