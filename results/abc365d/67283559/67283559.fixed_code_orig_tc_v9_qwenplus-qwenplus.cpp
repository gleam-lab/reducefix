#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;

    // We'll use a dynamic programming approach to track the maximum wins
    // dp[i][c] = max number of wins up to position i, ending with move c
    // where c can be 'R', 'P', or 'S'
    unordered_map<char, int> moves = {{'R', 0}, {'P', 0}, {'S', 0}};
    
    for (char c : S) {
        unordered_map<char, int> new_dp;
        for (auto &[last_move, win_count] : moves) {
            // Try playing each move
            for (char play : {'R', 'P', 'S'}) {
                if (play == last_move) continue;  // Cannot reuse the same move
                
                int score = 0;
                // Determine if this move beats the opponent's move
                if ((play == 'R' && c == 'S') ||
                    (play == 'P' && c == 'R') ||
                    (play == 'S' && c == 'P')) {
                    score = 1;
                }
                
                new_dp[play] = max(new_dp[play], win_count + score);
            }
        }
        moves = move(new_dp);
    }

    // The answer is the maximum value among all possible ending moves
    cout << (*max_element(moves.begin(), moves.end(),
                          [](const pair<char, int>& a, const pair<char, int>& b) {
                              return a.second < b.second;
                          }))->second << endl;

    return 0;
}