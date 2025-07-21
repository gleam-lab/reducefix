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

    // DP[i][c] represents the maximum wins up to position i, ending with move c
    vector<map<char, int>> dp(n);
    dp[0]['R'] = (beats[s[0]] == 'R') ? 1 : 0;
    dp[0]['P'] = (beats[s[0]] == 'P') ? 1 : 0;
    dp[0]['S'] = (beats[s[0]] == 'S') ? 1 : 0;

    for (int i = 1; i < n; i++) {
        for (char current : {'R', 'P', 'S'}) {
            int max_prev = 0;
            for (char prev : {'R', 'P', 'S'}) {
                if (prev != current) {
                    max_prev = max(max_prev, dp[i-1][prev]);
                }
            }
            dp[i][current] = max_prev + ((beats[s[i]] == current) ? 1 : 0);
        }
    }

    int max_wins = max({dp[n-1]['R'], dp[n-1]['P'], dp[n-1]['S']});
    cout << max_wins << endl;

    return 0;
}