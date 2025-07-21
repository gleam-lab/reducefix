#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    // DP[i][c] = max score up to position i with last move c
    vector<unordered_map<char, int>> dp(N);
    
    // Initialize first move possibilities
    dp[0]['R'] = (S[0] == 'S') ? 1 : 0;
    dp[0]['P'] = (S[0] == 'R') ? 1 : 0;
    dp[0]['S'] = (S[0] == 'P') ? 1 : 0;
    
    for (int i = 1; i < N; ++i) {
        char current = S[i];
        // For each possible current move
        for (char move : {'R', 'P', 'S'}) {
            int score = (move == 'R' && current == 'S') ? 1 :
                        (move == 'P' && current == 'R') ? 1 :
                        (move == 'S' && current == 'P') ? 1 : 0;
            
            // Find maximum from previous moves that are different
            int max_prev = 0;
            for (char prev_move : {'R', 'P', 'S'}) {
                if (prev_move != move && dp[i-1].count(prev_move)) {
                    max_prev = max(max_prev, dp[i-1][prev_move]);
                }
            }
            dp[i][move] = max_prev + score;
        }
    }
    
    // The answer is the maximum of the last moves
    int max_score = 0;
    for (auto& [move, score] : dp[N-1]) {
        max_score = max(max_score, score);
    }
    
    cout << max_score << endl;
    return 0;
}