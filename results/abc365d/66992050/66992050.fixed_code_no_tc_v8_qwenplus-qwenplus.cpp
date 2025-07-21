#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;
  string S;
  cin >> N >> S;

  // Initial state: no move made yet, so we can start with any move freely
  char last_move = 'N'; // 'N' means no previous move
  int ans = 0;

  for (char c : S) {
    if (c == 'P') { // Paper beats Rock
      if (last_move != 'R') {
        ans++;
        last_move = 'R';
      } else {
        last_move = 'P';
      }
    } 
    else if (c == 'R') { // Rock beats Scissors
      if (last_move != 'S') {
        ans++;
        last_move = 'S';
      } else {
        last_move = 'R';
      }
    } 
    else if (c == 'S') { // Scissors beats Paper
      if (last_move != 'P') {
        ans++;
        last_move = 'P';
      } else {
        last_move = 'S';
      }
    }
  }

  cout << ans << endl;
  return 0;
}