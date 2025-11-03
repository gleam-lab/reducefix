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

    // dp[i][c] = maximum rounds we can win ending with move c at position i
    vector<map<char, int>> dp(n);
    
    // Initialize first round
    for (char move : {'R', 'P', 'S'}) {
        if (beats[move] == s[0]) {
            dp[0][move] = 1; // We win if our move beats opponent's move
        } else {
            dp[0][move] = 0; // We lose or tie
        }
    }

    for (int i = 1; i < n; i++) {
        for (char curr_move : {'R', 'P', 'S'}) {
            dp[i][curr_move] = 0;
            // Check if current move wins against opponent's move
            bool win = (beats[curr_move] == s[i]);
            
            // Transition from previous state
            for (char prev_move : {'R', 'P', 'S'}) {
                if (dp[i-1].count(prev_move)) {
                    int candidate = dp[i-1][prev_move];
                    // If we won previous round, we can continue the streak
                    // If we lost previous round, we start fresh (but still count current win)
                    if (win) {
                        // We win this round
                        if (beats[prev_move] == s[i-1]) {
                            // Previous round was also a win - extend streak
                            candidate += 1;
                        } else {
                            // Previous round was loss/tie - start new streak with this win
                            candidate = 1;
                        }
                    } else {
                        // We don't win this round, so streak ends (but we don't add)
                        // The value remains as previous (carry forward best score even without winning)
                    }
                    
                    // For non-winning moves, we just carry forward the best score so far
                    if (!win) {
                        candidate = dp[i-1][prev_move];
                    }
                    
                    dp[i][curr_move] = max(dp[i][curr_move], candidate);
                }
            }
        }
    }

    // Find maximum value in the last row
    int result = 0;
    for (auto& p : dp[n-1]) {
        result = max(result, p.second);
    }
    
    // Also consider the possibility of not playing optimally from start
    // Let's use a simpler greedy approach that tracks when we can win
    
    int total_wins = 0;
    char last_played = beats[s[0]]; // Our move that beats first opponent move
    
    for (int i = 0; i < n; i++) {
        // Try to maximize consecutive wins
        if (i == 0) {
            if (beats[last_played] == s[i]) {
                total_wins = 1;
            }
        } else {
            // If we can continue winning streak
            if (beats[last_played] == s[i]) {
                total_wins++;
            } else {
                // Start new potential streak
                last_played = beats[s[i]];
                total_wins = 1;
            }
        }
    }
    
    // Use dynamic programming solution which is more accurate
    // Reset and implement correct DP
    vector<int> dp2(n, 0);
    
    // dp2[i] = maximum wins possible up to round i
    for (int i = 0; i < n; i++) {
        // Option 1: Don't win at position i
        if (i > 0) {
            dp2[i] = dp2[i-1];
        }
        
        // Option 2: Win at position i
        // Find longest sequence ending with a win at i
        int wins = 0;
        char my_move = beats[s[i]];
        
        // Go backwards to extend winning streak
        for (int j = i; j >= 0; j--) {
            char required_move = beats[s[j]];
            if (j < i && required_move != my_move) {
                // Streak broken, but we can still have single win
                break;
            }
            if (beats[my_move] == s[j]) {
                wins++;
                if (j == 0) {
                    dp2[i] = max(dp2[i], wins);
                } else {
                    dp2[i] = max(dp2[i], dp2[j-1] + wins);
                }
            } else {
                break;
            }
        }
    }
    
    cout << (n > 0 ? dp2[n-1] : 0) << endl;

    return 0;
}