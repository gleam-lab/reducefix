#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    // DP table: dp[i][c] = max score up to position i ending with move c
    // c: 0=R, 1=P, 2=S
    vector<vector<int>> dp(N, vector<int>(3, 0));
    
    // Initialize first move
    for (int c = 0; c < 3; c++) {
        char move = (c == 0) ? 'R' : (c == 1) ? 'P' : 'S';
        if (move == 'R' && S[0] == 'S') dp[0][c] = 1;
        else if (move == 'P' && S[0] == 'R') dp[0][c] = 1;
        else if (move == 'S' && S[0] == 'P') dp[0][c] = 1;
    }
    
    for (int i = 1; i < N; i++) {
        for (int c = 0; c < 3; c++) {
            char move = (c == 0) ? 'R' : (c == 1) ? 'P' : 'S';
            int score = 0;
            if (move == 'R' && S[i] == 'S') score = 1;
            else if (move == 'P' && S[i] == 'R') score = 1;
            else if (move == 'S' && S[i] == 'P') score = 1;
            
            // Can't use same move as previous
            for (int prev_c = 0; prev_c < 3; prev_c++) {
                if (prev_c != c) {
                    dp[i][c] = max(dp[i][c], dp[i-1][prev_c] + score);
                }
            }
        }
    }
    
    int max_score = max({dp[N-1][0], dp[N-1][1], dp[N-1][2]});
    cout << max_score << endl;
    return 0;
}