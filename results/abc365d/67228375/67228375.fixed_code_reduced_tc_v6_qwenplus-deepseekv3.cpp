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

    vector<vector<int>> dp(n, vector<int>(3, 0));
    dp[0][0] = (beats['R'] == s[0]) ? 1 : 0;
    dp[0][1] = (beats['P'] == s[0]) ? 1 : 0;
    dp[0][2] = (beats['S'] == s[0]) ? 1 : 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            char current_move;
            if (j == 0) current_move = 'R';
            else if (j == 1) current_move = 'P';
            else current_move = 'S';

            int max_prev = 0;
            for (int k = 0; k < 3; k++) {
                char prev_move;
                if (k == 0) prev_move = 'R';
                else if (k == 1) prev_move = 'P';
                else prev_move = 'S';

                if (beats[prev_move] == current_move) {
                    max_prev = max(max_prev, dp[i-1][k] + 1);
                } else {
                    max_prev = max(max_prev, dp[i-1][k]);
                }
            }
            dp[i][j] = max_prev;
        }
    }

    int max_wins = max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    cout << max_wins << endl;

    return 0;
}