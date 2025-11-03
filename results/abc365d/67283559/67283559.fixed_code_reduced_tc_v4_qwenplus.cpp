#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;

  vector<char> hand = {'R','P','S'};
  int max_score = 0;

  // Try all possible starting choices
  for (char start : hand) {
    vector<char> available = hand;
    auto it = find(available.begin(), available.end(), start);
    if (it != available.end()) {
      available.erase(it);
    }

    int score = 0;
    char current_use = start;

    // First move is fixed to 'start'
    if (start == 'R' && S[0] == 'S') score++;
    else if (start == 'P' && S[0] == 'R') score++;
    else if (start == 'S' && S[0] == 'P') score++;

    // Simulate the rest of the moves
    for (int i = 1; i < N; i++) {
      char best_move = available[0];
      bool can_win = false;

      // Check if any available move can win
      for (char move : available) {
        if ((move == 'R' && S[i] == 'S') ||
            (move == 'P' && S[i] == 'R') ||
            (move == 'S' && S[i] == 'P')) {
          best_move = move;
          can_win = true;
          break;
        }
      }

      // If we can win, use that move; otherwise, use any (preferably one that doesn't lose)
      if (can_win) {
        score++;
      } else {
        // Even if we can't win, we pick a move (we'll just use best_move which is first available)
        // But try to avoid losing if possible? Actually, no choice — both might lose or tie.
        // We just proceed with best_move (already set).
      }

      // Update available moves: remove the one we used
      vector<char> new_available;
      for (char move : hand) {
        if (move != best_move) {
          new_available.push_back(move);
        }
      }
      available = new_available;
      current_use = best_move;
    }

    max_score = max(max_score, score);
  }

  cout << max_score << endl;
}