#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // dummy case
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    // DP[i][0] = max wins up to i-th position when choosing 'R'
    // DP[i][1] = max wins up to i-th position when choosing 'P'
    // DP[i][2] = max wins up to i-th position when choosing 'S'
    vector<vector<int>> dp(n, vector<int>(3, 0));

    // Initialize the first position
    dp[0][0] = (win(s[0]) == 'R') ? 1 : 0;
    dp[0][1] = (win(s[0]) == 'P') ? 1 : 0;
    dp[0][2] = (win(s[0]) == 'S') ? 1 : 0;

    for (int i = 1; i < n; ++i) {
        // Current choice is 'R'
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + ((win(s[i]) == 'R') ? 1 : 0);
        // Current choice is 'P'
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + ((win(s[i]) == 'P') ? 1 : 0);
        // Current choice is 'S'
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + ((win(s[i]) == 'S') ? 1 : 0);
    }

    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;

    return 0;
}