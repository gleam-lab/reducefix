#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  string S;
  cin >> N >> S;

  char last_move = 'N'; // Initial state, no move yet
  int wins = 0;

  for (char c : S) {
    if (c == 'R') { // Rock
      if (last_move != 'P') {
        wins++;
        last_move = 'P'; // Paper beats Rock
      } else {
        last_move = 'R';
      }
    } else if (c == 'P') { // Paper
      if (last_move != 'S') {
        wins++;
        last_move = 'S'; // Scissors beat Paper
      } else {
        last_move = 'P';
      }
    } else if (c == 'S') { // Scissors
      if (last_move != 'R') {
        wins++;
        last_move = 'R'; // Rock beats Scissors
      } else {
        last_move = 'S';
      }
    }
  }

  cout << wins << endl;
  return 0;
}