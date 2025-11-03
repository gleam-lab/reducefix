#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    string S;
    cin >> N >> S;
    
    // We want to minimize the number of hand changes
    // This is equivalent to maximizing consecutive same moves
    // We can use dynamic programming where state represents last move
    
    // dp[i][c] = minimum changes needed up to position i, ending with move c
    // c: 0=P, 1=R, 2=S
    const int INF = 1e9;
    
    vector<vector<int>> dp(N+1, vector<int>(3, INF));
    
    // Base case: before any move, we haven't made any changes
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    
    auto charToIdx = [](char c) {
        if (c == 'P') return 0;
        if (c == 'R') return 1;
        return 2;
    };
    
    for (int i = 0; i < N; i++) {
        int target = charToIdx(S[i]);
        
        // Try all possible current moves
        for (int curr = 0; curr < 3; curr++) {
            if (dp[i][curr] == INF) continue;
            
            // Check if current move is allowed
            // Only the target move is allowed at this step
            if (curr != target) {
                // We need to change move
                for (int prev = 0; prev < 3; prev++) {
                    if (prev == curr) continue; // Can't stay with same move
                    dp[i+1][curr] = min(dp[i+1][curr], dp[i][prev] + 1);
                }
            } else {
                // We can either keep the same move or change to it
                // Keep same move - no additional change
                dp[i+1][curr] = min(dp[i+1][curr], dp[i][curr]);
                
                // Change from different move
                for (int prev = 0; prev < 3; prev++) {
                    if (prev == curr) continue;
                    dp[i+1][curr] = min(dp[i+1][curr], dp[i][prev] + 1);
                }
            }
        }
    }
    
    int ans = min({dp[N][0], dp[N][1], dp[N][2]});
    cout << ans;
    return 0;
}