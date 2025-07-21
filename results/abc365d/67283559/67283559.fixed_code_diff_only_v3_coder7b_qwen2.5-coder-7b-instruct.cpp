#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<char> hand{'R', 'P', 'S'};
    vector<int> dp(N + 1, 0);
    vector<vector<int>> last(N + 1, vector<int>(4));

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < 3; ++j) {
            dp[i] = max(dp[i], dp[last[i - 1][j]]);
        }

        for (int j = 0; j < 3; ++j) {
            if ((hand[j] == 'R' && S[i - 1] == 'S') ||
                (hand[j] == 'P' && S[i - 1] == 'R') ||
                (hand[j] == 'S' && S[i - 1] == 'P')) {
                dp[i] += 1;
                last[i][j] = i;
            } else {
                last[i][j] = last[i - 1][j];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 3; ++i) {
        ans = max(ans, dp[N]);
    }

    cout << ans << endl;

    return 0;
}