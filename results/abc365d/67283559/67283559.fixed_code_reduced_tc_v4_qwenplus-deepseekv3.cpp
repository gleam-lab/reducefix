#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    // DP table: dp[i][m] represents the max score up to position i with move m
    vector<vector<int>> dp(N, vector<int>(3, 0));
    
    // Initialize the first move
    for (int m = 0; m < 3; ++m) {
        char move = (m == 0) ? 'R' : (m == 1) ? 'P' : 'S';
        if (move == 'R' && S[0] == 'S') dp[0][m] = 1;
        else if (move == 'P' && S[0] == 'R') dp[0][m] = 1;
        else if (move == 'S' && S[0] == 'P') dp[0][m] = 1;
    }
    
    // Fill the DP table
    for (int i = 1; i < N; ++i) {
        for (int m = 0; m < 3; ++m) {
            char move = (m == 0) ? 'R' : (m == 1) ? 'P' : 'S';
            int current_score = 0;
            if (move == 'R' && S[i] == 'S') current_score = 1;
            else if (move == 'P' && S[i] == 'R') current_score = 1;
            else if (move == 'S' && S[i] == 'P') current_score = 1;
            
            // The previous move cannot be the same as the current move
            for (int prev_m = 0; prev_m < 3; ++prev_m) {
                if (prev_m != m) {
                    dp[i][m] = max(dp[i][m], dp[i-1][prev_m] + current_score);
                }
            }
        }
    }
    
    // The answer is the maximum score achievable at the last position
    int max_score = max({dp[N-1][0], dp[N-1][1], dp[N-1][2]});
    cout << max_score << endl;
    
    return 0;
}