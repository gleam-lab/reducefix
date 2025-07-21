#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;

    // dp[i] will store the minimum number of moves needed to win up to the i-th character
    vector<int> dp(n + 1, 0);

    // The first move is simply the move that beats the first character
    dp[1] = 1;

    // For each subsequent character, decide whether to make a new move or continue with the current one
    for (int i = 2; i <= n; ++i) {
        if (beats[s[i - 1]] == beats[s[i - 2]]) {
            // If the move needed to beat current and previous are the same, no additional move is needed
            dp[i] = dp[i - 1];
        } else {
            // Otherwise, we need a new move
            dp[i] = dp[i - 1] + 1;
        }
    }

    cout << dp[n] << endl;

    return 0;
}