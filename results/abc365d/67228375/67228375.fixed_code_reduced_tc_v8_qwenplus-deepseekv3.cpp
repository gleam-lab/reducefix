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

    vector<map<char, int>> dp(n);
    dp[0]['R'] = 1;
    dp[0]['P'] = 1;
    dp[0]['S'] = 1;
    dp[0][s[0]] = 1;

    for (int i = 1; i < n; ++i) {
        char current = s[i];
        dp[i]['R'] = max(dp[i-1]['R'], (current == 'R') ? dp[i-1]['S'] + 1 : dp[i-1]['S']);
        dp[i]['P'] = max(dp[i-1]['P'], (current == 'P') ? dp[i-1]['R'] + 1 : dp[i-1]['R']);
        dp[i]['S'] = max(dp[i-1]['S'], (current == 'S') ? dp[i-1]['P'] + 1 : dp[i-1]['P']);

        dp[i][current] = max(dp[i][current], max({dp[i-1]['R'], dp[i-1]['P'], dp[i-1]['S']}) + 1);
    }

    cout << max({dp[n-1]['R'], dp[n-1]['P'], dp[n-1]['S']}) << endl;

    return 0;
}