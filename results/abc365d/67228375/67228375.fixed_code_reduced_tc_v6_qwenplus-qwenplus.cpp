#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

char beat(char c) {
    if (c == 'R') return 'P';
    if (c == 'P') return 'S';
    return 'R';
}

int solve(const string& s) {
    int n = s.size();
    if (n == 0) return 0;

    // dp[i][0] = max wins ending with move s[i]
    // dp[i][1] = max wins ending with move beat(s[i])
    vector<vector<int>> dp(n, vector<int>(2, 0));
    
    dp[0][0] = 1; // use s[0]
    dp[0][1] = 1; // use beat(s[0])

    for (int i = 1; i < n; ++i) {
        // Case 1: use current character
        dp[i][0] = 1;
        if (beat(s[i]) != beat(s[i-1])) dp[i][0] = max(dp[i][0], dp[i-1][0] + 1);
        else dp[i][0] = max(dp[i][0], dp[i-1][0]);
        
        // Case 2: use the move that beats current character
        char curr_beat = beat(s[i]);
        dp[i][1] = 1;
        if (curr_beat != beat(s[i-1])) {
            dp[i][1] = max(dp[i][1], dp[i-1][1] + 1);
        } else {
            dp[i][1] = max(dp[i][1], dp[i-1][1]);
        }
        
        // Also consider switching from previous regular move
        if (curr_beat != s[i-1]) {
            dp[i][1] = max(dp[i][1], dp[i-1][0] + 1);
        }
    }

    return max(dp[n-1][0], dp[n-1][1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    cout << solve(s) << endl;

    return 0;
}