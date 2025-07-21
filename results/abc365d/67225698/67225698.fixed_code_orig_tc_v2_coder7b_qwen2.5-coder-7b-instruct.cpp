#include <bits/stdc++.h>
using namespace std;

const int MAXN = 26; // Assuming only lowercase English letters
const int MOD = 1e9 + 7;

int distinctSubseqII(string s) {
    int n = s.length();
    vector<int> last(26, -1); // To store the last occurrence of each character
    vector<int> dp(n + 1, 0); // DP array to store the number of distinct subsequences up to index i
    dp[0] = 1; // Base case: one empty subsequence

    for (int i = 1; i <= n; ++i) {
        char c = s[i - 1];
        dp[i] = (dp[i - 1] * 2) % MOD; // Double the previous count as every new character doubles the subsequences
        if (last[c - 'a'] != -1) {
            dp[i] = (dp[i] - dp[last[c - 'a']] + MOD) % MOD; // Subtract subsequences ending with the same character before its last occurrence
        }
        last[c - 'a'] = i - 1; // Update the last occurrence of the current character
    }

    return (dp[n] - 1 + MOD) % MOD; // Subtract one to exclude the empty subsequence and take modulo to prevent overflow
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // Uncomment the line below to use multiple test cases
    // cin >> t;

    while (t--) {
        string s;
        cin >> s;
        cout << distinctSubseqII(s) << '\n';
    }

    return 0;
}