#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int N;
  string S;
  cin >> N >> S;
  if (N == 0) {
    cout << 0;
    return 0;
  }
  char past = S[0];
  int ans = 0;
  for (int i = 1; i < N; ++i) {
    char current = S[i];
    if (current == 'P') {
      if (past == 'S') {
        ans++;
        past = 'P';
      } else if (past != 'P') {
        past = current;
      }
    } else if (current == 'R') {
      if (past == 'P') {
        ans++;
        past = 'R';
      } else if (past != 'R') {
        past = current;
      }
    } else if (current == 'S') {
      if (past == 'R') {
        ans++;
        past = 'S';
      } else if (past != 'S') {
        past = current;
      }
    }
  }
  cout << ans;
  return 0;
}