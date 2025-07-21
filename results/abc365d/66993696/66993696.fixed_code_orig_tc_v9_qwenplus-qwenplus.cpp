#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    
    cin >> n >> s;

    vector<int> dp(n + 1, 0);  // dp[i] = max number of changes we can make up to position i
    
    // We need to ensure that no two consecutive characters in the transformed string are the same
    // For each position i, we can either:
    // - change it (cost 1), ensuring it's different from previous
    // - not change it (cost 0), only if it's already different from previous

    for (int i = 1; i < n; ++i) {
        // Case 1: If current character is different from previous one, we can keep both unchanged
        // So no cost added
        if (s[i] != s[i - 1]) {
            dp[i + 1] = dp[i];
        } else {
            // Case 2: Characters are equal. We have to change at least one of them.
            // Try changing current character
            dp[i + 1] = dp[i] + 1;
        }
    }

    cout << n - dp[n] << '\n';
}