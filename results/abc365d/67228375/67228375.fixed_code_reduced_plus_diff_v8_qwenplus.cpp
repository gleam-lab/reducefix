#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    // dp[i][last] = maximum number of rounds we can win up to index i with last move being 'last'
    // We only need the previous state, so we use two maps for space efficiency
    map<char, int> prev_dp;
    // Initialize with first character
    prev_dp[beats[s[0]]] = 1; // we choose the move that beats opponent's first move
    prev_dp[s[0]] = 0; // or we can choose to match (but this doesn't win)

    for (int i = 1; i < n; i++) {
        map<char, int> curr_dp;
        char opp_move = s[i];
        char beat_move = beats[opp_move];
        
        // Try all possible moves for current round
        for (char my_move : {'R', 'P', 'S'}) {
            int best = 0;
            // Check transitions from all possible previous moves
            for (auto &[prev_move, wins] : prev_dp) {
                // If our current move is valid (i.e., not creating a cycle)
                // In RPS, as long as we're making a move, it's valid
                // The only constraint is that we can't have a situation where moves force a loss
                // But in this problem, we just want to maximize wins
                
                // If my_move beats opponent's move, we win this round
                int additional_win = (beats[opp_move] == my_move) ? 1 : 0;
                
                // In standard RPS there are no restrictions on consecutive moves,
                // so we can transition from any previous state
                best = max(best, wins + additional_win);
            }
            curr_dp[my_move] = best;
        }
        prev_dp = curr_dp;
    }

    int result = 0;
    for (auto &[move, wins] : prev_dp) {
        result = max(result, wins);
    }
    
    cout << result << endl;

    return 0;
}