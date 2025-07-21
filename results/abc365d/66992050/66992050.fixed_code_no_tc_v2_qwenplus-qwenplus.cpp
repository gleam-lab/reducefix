#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  string S;
  cin >> N >> S;

  // Mapping from move to its winning move
  unordered_map<char, char> beats = {
      {'R', 'S'},  // Rock beats Scissors
      {'S', 'P'},  // Scissors beats Paper
      {'P', 'R'}   // Paper beats Rock
  };

  char last_move = 'N';  // No previous move at the beginning
  int ans = 0;

  for (char c : S) {
    if (last_move == 'N' || last_move == beats[c]) {
      // We win or it's the first move
      ans++;
      last_move = c;
    } else {
      // Choose the winning move against current opponent move
      last_move = beats[c];
    }
  }

  cout << ans << endl;
  return 0;
}