#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    // The key insight: we want to maximize wins over the sequence
    // We can choose any move at each step, but cannot repeat the same move twice consecutively
    
    // dp[i][move] = maximum wins up to position i, ending with 'move'
    // where move: 0='R', 1='P', 2='S'
    
    vector<vector<int>> dp(N, vector<int>(3, 0));
    
    // Initialize first move
    if (S[0] == 'R') {
        dp[0][0] = 0; // R vs R -> tie
        dp[0][1] = 1; // P vs R -> win
        dp[0][2] = 0; // S vs R -> loss
    } else if (S[0] == 'P') {
        dp[0][0] = 0; // R vs P -> loss
        dp[0][1] = 0; // P vs P -> tie
        dp[0][2] = 1; // S vs P -> win
    } else { // S[0] == 'S'
        dp[0][0] = 1; // R vs S -> win
        dp[0][1] = 0; // P vs S -> loss
        dp[0][2] = 0; // S vs S -> tie
    }
    
    // Fill DP table
    for (int i = 1; i < N; i++) {
        for (int last = 0; last < 3; last++) {
            for (int curr = 0; curr < 3; curr++) {
                if (last == curr) continue; // Cannot use same move twice
                
                int win = 0;
                char my_move = "RPS"[curr];
                char opp_move = S[i];
                
                if ((my_move == 'R' && opp_move == 'S') ||
                    (my_move == 'P' && opp_move == 'R') ||
                    (my_move == 'S' && opp_move == 'P')) {
                    win = 1;
                }
                
                dp[i][curr] = max(dp[i][curr], dp[i-1][last] + win);
            }
        }
    }
    
    // Find maximum wins from last position
    int result = max({dp[N-1][0], dp[N-1][1], dp[N-1][2]});
    cout << result << endl;
    
    return 0;
}