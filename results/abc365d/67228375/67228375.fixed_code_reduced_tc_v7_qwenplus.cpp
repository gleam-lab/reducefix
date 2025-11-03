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

    // dp[i][move] = maximum rounds won up to index i, where we choose 'move' at position i
    // move can be the same as s[i] (we play losing move) or beats[s[i]] (we play winning move)
    // Actually, we only care about whether we win or not at each step.

    // Alternate approach:
    // At each position, we can choose to play:
    //   Option 1: beats[s[i]] -> we win this round
    //   Option 2: anything else -> we lose or tie

    // But our choice affects the next round because of the "last move" rule.
    // We cannot play a move that would have been beaten by our previous move.

    // State: dp[i][last_played] = max wins from 0..i with last played move
    // But state space is small (only R, P, S)

    vector<map<char, int>> dp(n); // dp[i][c] = max wins up to i ending with move c

    // Initialize first round
    char win_move = beats[s[0]];
    char lose_move = s[0]; // or any move that doesn't beat s[0], but we need to pick one

    dp[0][win_move] = 1; // if we play winning move
    dp[0][lose_move] = 0; // if we play losing/tie move

    // Also consider the other losing option if different
    for (char c : {'R', 'P', 'S'}) {
        if (c != win_move && c != lose_move) {
            dp[0][c] = 0;
        }
    }

    for (int i = 1; i < n; i++) {
        char win_move_curr = beats[s[i]];
        for (char curr : {'R', 'P', 'S'}) {
            int win_curr = (curr == win_move_curr) ? 1 : 0;
            for (char prev : {'R', 'P', 'S'}) {
                if (dp[i-1].count(prev)) {
                    // Check if current move is allowed after previous move
                    // Rule: we cannot play a move that would have been beaten by our previous move
                    // That is, we cannot play x such that beats[x] == prev
                    // So we must have: beats[curr] != prev
                    if (beats[curr] == prev) {
                        continue;
                    }
                    if (dp[i].count(curr)) {
                        dp[i][curr] = max(dp[i][curr], dp[i-1][prev] + win_curr);
                    } else {
                        dp[i][curr] = dp[i-1][prev] + win_curr;
                    }
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