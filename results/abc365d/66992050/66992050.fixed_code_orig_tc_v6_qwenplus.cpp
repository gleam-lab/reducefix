#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    string S;
    cin >> N >> S;
    
    // We want to minimize the number of hand changes
    // This is equivalent to maximizing consecutive same moves
    // We can use dynamic programming where:
    // dp[i][c] = minimum moves needed up to index i, ending with move c
    
    const int INF = 1e9;
    vector<array<int, 3>> dp(N + 1);
    
    // Initialize: before any move, we haven't made any moves
    dp[0]['R'-'P'] = dp[0]['P'-'P'] = dp[0]['S'-'P'] = 0;
    
    auto getIdx = [](char c) {
        return c - 'P';
    };
    
    for (int i = 0; i < N; i++) {
        char required = S[i];
        int r_idx = getIdx('R');
        int p_idx = getIdx('P');
        int s_idx = getIdx('S');
        
        // For each possible current move, compute minimum cost
        dp[i+1][r_idx] = min({
            dp[i][r_idx],           // same as previous R
            dp[i][p_idx] + 1,       // switch from P to R
            dp[i][s_idx] + 1        // switch from S to R
        });
        
        dp[i+1][p_idx] = min({
            dp[i][p_idx],           // same as previous P
            dp[i][r_idx] + 1,       // switch from R to P
            dp[i][s_idx] + 1        // switch from S to P
        });
        
        dp[i+1][s_idx] = min({
            dp[i][s_idx],           // same as previous S
            dp[i][r_idx] + 1,       // switch from R to S
            dp[i][p_idx] + 1        // switch from P to S
        });
        
        // If current character doesn't allow certain moves, set those to infinity
        if (required == 'R') {
            dp[i+1][p_idx] = INF;
            dp[i+1][s_idx] = INF;
        } else if (required == 'P') {
            dp[i+1][r_idx] = INF;
            dp[i+1][s_idx] = INF;
        } else if (required == 'S') {
            dp[i+1][r_idx] = INF;
            dp[i+1][p_idx] = INF;
        }
    }
    
    int ans = min({dp[N][getIdx('R')], dp[N][getIdx('P')], dp[N][getIdx('S')]});
    cout << ans;
    return 0;
}