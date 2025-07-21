#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  string S;
  cin >> N >> S;

  // Mapping of moves to their respective counters
  // R < P < S < R (Rock beats Scissors, Paper beats Rock, Scissors beats Paper)
  unordered_map<char, char> counterMove = {
      {'R', 'P'},  // Paper beats Rock
      {'P', 'S'},  // Scissors beats Paper
      {'S', 'R'}   // Rock beats Scissors
  };

  char lastMove = 'N';  // No previous move at start
  int ans = 0;

  for (char c : S) {
    if (lastMove == 'N' || lastMove == counterMove[c]) {
      // If first move or opponent's move is beaten by our last move, we win; increment score
      ans++;
      // Continue with the same winning move
      lastMove = counterMove[c];
    } else {
      // We lost or drew, switch to counter the current move
      lastMove = counterMove[c];
    }
  }

  cout << ans << endl;
  return 0;
}