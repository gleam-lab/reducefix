#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(3, 0));
    char first_move = s[0];
    dp[0][0] = (beats[first_move] == 'R') ? 1 : 0; // Last move was R
    dp[0][1] = (beats[first_move] == 'P') ? 1 : 0; // Last move was P
    dp[0][2] = (beats[first_move] == 'S') ? 1 : 0; // Last move was S

    for (int i = 1; i < n; ++i) {
        char current = s[i];
        int win_R = (beats[current] == 'R') ? 1 : 0;
        int win_P = (beats[current] == 'P') ? 1 : 0;
        int win_S = (beats[current] == 'S') ? 1 : 0;

        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + win_R;
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + win_P;
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + win_S;
    }

    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;

    return 0;
}