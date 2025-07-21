#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  string S;
  cin >> N >> S;

  // Mapping of moves to their respective counters
  unordered_map<char, char> counterMove = {
      {'R', 'P'},  // Rock is beaten by Paper
      {'P', 'S'},  // Paper is beaten by Scissors
      {'S', 'R'}   // Scissors are beaten by Rock
  };

  char last_move = 'N';  // No previous move at the start
  int ans = 0;

  for (char c : S) {
    if (last_move == 'N' || last_move == counterMove[c]) {
      // We either just started or the opponent's move beats our last move
      // So we change to the counter move
      ans++;
    }
    // Update last move to the move that would beat the opponent's current move
    last_move = counterMove[c];
  }

  cout << ans << endl;
  return 0;
}