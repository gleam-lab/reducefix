#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    // dp[i][c] = minimum number of changes needed for prefix ending at i with final character c
    // where c: 0='R', 1='P', 2='S'
    vector<vector<int>> dp(n, vector<int>(3, n));
    
    // Initialize first character
    for (int j = 0; j < 3; j++) {
        char target = "RPS"[j];
        dp[0][j] = (s[0] != target) ? 1 : 0;
    }
    
    // Transition: each state can come from any previous state
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) { // current character
            char curr = "RPS"[j];
            int cost = (s[i] != curr) ? 1 : 0;
            
            // Can transition from any previous state
            int prev_min = *min_element(dp[i-1].begin(), dp[i-1].end());
            dp[i][j] = prev_min + cost;
        }
    }
    
    cout << *min_element(dp[n-1].begin(), dp[n-1].end()) << endl;
    
    return 0;
}