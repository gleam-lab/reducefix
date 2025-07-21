#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    // Initialize DP table: dp[i][j] where j represents the last move (0: R, 1: P, 2: S)
    vector<vector<int>> dp(N, vector<int>(3, 0));
    
    // Initialize the first move
    for (int j = 0; j < 3; ++j) {
        char move = (j == 0) ? 'R' : (j == 1) ? 'P' : 'S';
        if (move == 'R' && S[0] == 'S') dp[0][j] = 1;
        else if (move == 'P' && S[0] == 'R') dp[0][j] = 1;
        else if (move == 'S' && S[0] == 'P') dp[0][j] = 1;
    }
    
    for (int i = 1; i < N; ++i) {
        for (int prev_j = 0; prev_j < 3; ++prev_j) {
            if (dp[i-1][prev_j] == -1) continue; // Skip invalid previous states
            for (int curr_j = 0; curr_j < 3; ++curr_j) {
                if (curr_j == prev_j) continue; // Cannot use the same move as the previous one
                char move = (curr_j == 0) ? 'R' : (curr_j == 1) ? 'P' : 'S';
                int score = 0;
                if (move == 'R' && S[i] == 'S') score = 1;
                else if (move == 'P' && S[i] == 'R') score = 1;
                else if (move == 'S' && S[i] == 'P') score = 1;
                dp[i][curr_j] = max(dp[i][curr_j], dp[i-1][prev_j] + score);
            }
        }
    }
    
    int max_score = 0;
    for (int j = 0; j < 3; ++j) {
        max_score = max(max_score, dp[N-1][j]);
    }
    
    cout << max_score << endl;
    return 0;
}