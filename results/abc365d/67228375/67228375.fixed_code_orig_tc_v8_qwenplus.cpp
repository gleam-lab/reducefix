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

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    // dp[i][move] = max rounds won ending with move at position i
    vector<map<char, int>> dp(n);
    
    // Initialize first character
    dp[0][beats[s[0]]] = 1;  // We can win by playing the move that beats opponent's first move
    dp[0][s[0]] = 0;         // Or play same move (tie, no win)

    for (int i = 1; i < n; i++) {
        char opp_move = s[i];
        char winning_move = beats[opp_move];
        char losing_move = beats[winning_move]; // The move that loses to opponent's move
        
        // Try all possible moves from previous state
        int best_without_current_win = 0;
        int best_with_current_win = 0;
        
        // Find best value for each scenario
        for (auto& [prev_move, wins] : dp[i-1]) {
            // If we can play winning move (get +1 win)
            if (wins > best_with_current_win) {
                best_with_current_win = wins;
            }
            
            // For non-winning moves, just carry forward
            if (wins > best_without_current_win) {
                best_without_current_win = wins;
            }
        }
        
        // We can always achieve best_without_current_win by playing a non-winning move
        dp[i][losing_move] = max(dp[i][losing_move], best_without_current_win);
        dp[i][opp_move] = max(dp[i][opp_move], best_without_current_win);
        
        // We can achieve best_with_current_win + 1 by playing winning move
        dp[i][winning_move] = max(dp[i][winning_move], best_with_current_win + 1);
    }
    
    // Find maximum wins from last position
    int result = 0;
    for (auto& [move, wins] : dp[n-1]) {
        result = max(result, wins);
    }
    
    cout << result << endl;
    return 0;
}