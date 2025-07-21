#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    // DP table: dp[i][c] = max score up to position i with last move c
    // where c is 0 (R), 1 (P), or 2 (S)
    vector<vector<int>> dp(N, vector<int>(3, 0));
    
    // Initialize first move
    for (int c = 0; c < 3; c++) {
        char move;
        if (c == 0) move = 'R';
        else if (c == 1) move = 'P';
        else move = 'S';
        
        if (move == 'R' && S[0] == 'S') dp[0][c] = 1;
        else if (move == 'P' && S[0] == 'R') dp[0][c] = 1;
        else if (move == 'S' && S[0] == 'P') dp[0][c] = 1;
    }
    
    for (int i = 1; i < N; i++) {
        for (int curr = 0; curr < 3; curr++) {
            char curr_move;
            if (curr == 0) curr_move = 'R';
            else if (curr == 1) curr_move = 'P';
            else curr_move = 'S';
            
            // Compute current score
            int curr_score = 0;
            if (curr_move == 'R' && S[i] == 'S') curr_score = 1;
            else if (curr_move == 'P' && S[i] == 'R') curr_score = 1;
            else if (curr_move == 'S' && S[i] == 'P') curr_score = 1;
            
            // Find best previous move that's different from current
            int max_prev = 0;
            for (int prev = 0; prev < 3; prev++) {
                if (prev != curr) {
                    max_prev = max(max_prev, dp[i-1][prev]);
                }
            }
            
            dp[i][curr] = max_prev + curr_score;
        }
    }
    
    // Result is maximum of the last moves
    int result = max({dp[N-1][0], dp[N-1][1], dp[N-1][2]});
    cout << result << endl;
    
    return 0;
}