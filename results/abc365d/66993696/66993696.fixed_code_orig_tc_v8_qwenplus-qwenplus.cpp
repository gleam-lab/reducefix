#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    string s;
    
    cin >> n >> s;
    
    // The problem is equivalent to finding the longest subsequence where no two adjacent characters are the same
    // after applying a transformation (P -> S, R -> P, S -> R). This transformation can be seen as a cyclic shift.
    // We can model this as a DP problem with three states (last character being P, R, or S).
    
    const char trans[3] = {'S', 'P', 'R'}; // Transformation: P->S, R->P, S->R
    
    // dp[i][c]: max length of valid subsequence for first i chars ending with trans[c]
    vector<vector<int>> dp(2, vector<int>(3));
    
    for (int i = 0; i < n; ++i) {
        int curr = i % 2;
        int prev = (i + 1) % 2;
        
        for (int c = 0; c < 3; ++c) {
            // Transform current character
            char transformed = (s[i] == 'P' ? 'S' : (s[i] == 'R' ? 'P' : 'R'));
            
            if (transformed == trans[c]) {
                // Take current character if it matches target
                dp[curr][c] = max(dp[prev][0], max(dp[prev][1], dp[prev][2])) + 1;
            } else {
                // Skip current character
                dp[curr][c] = dp[prev][c];
            }
        }
    }
    
    cout << max(dp[(n-1)%2][0], max(dp[(n-1)%2][1], dp[(n-1)%2][2]));
    return 0;
}