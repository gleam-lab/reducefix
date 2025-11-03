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

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    // dp[i][move] = max rounds we can win up to index i, where move is the move we made at round i
    vector<map<char, int>> dp(n);
    
    // Initialize first round
    for (char c : {'R', 'P', 'S'}) {
        if (beats[c] == s[0]) {
            dp[0][c] = 1; // We win if our move beats opponent's move
        } else {
            dp[0][c] = 0; // We lose or tie
        }
    }

    for (int i = 1; i < n; i++) {
        for (char curr : {'R', 'P', 'S'}) {
            dp[i][curr] = 0;
            bool win = (beats[curr] == s[i]);
            int base = win ? 1 : 0;
            
            // Transition from previous state
            for (char prev : {'R', 'P', 'S'}) {
                if (dp[i-1].count(prev)) {
                    // If current move is same as previous, no additional cost
                    // If different, it's allowed (no restriction on changing moves)
                    dp[i][curr] = max(dp[i][curr], dp[i-1][prev] + base);
                }
            }
        }
    }

    int ans = 0;
    for (auto& p : dp[n-1]) {
        ans = max(ans, p.second);
    }
    
    cout << ans << endl;

    return 0;
}