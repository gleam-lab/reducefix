#include <bits/stdc++.h>
using namespace std;

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
    dp[0][0] = (beats[s[0]] == 'R') ? 1 : 0;
    dp[0][1] = (beats[s[0]] == 'P') ? 1 : 0;
    dp[0][2] = (beats[s[0]] == 'S') ? 1 : 0;

    for (int i = 1; i < n; ++i) {
        char current = s[i];
        char winning_move = beats[current];
        int current_win = 0;

        for (int prev_move = 0; prev_move < 3; ++prev_move) {
            for (int curr_move = 0; curr_move < 3; ++curr_move) {
                char move_char;
                if (curr_move == 0) move_char = 'R';
                else if (curr_move == 1) move_char = 'P';
                else move_char = 'S';

                int win_add = (move_char == winning_move) ? 1 : 0;
                if (prev_move != curr_move) {
                    dp[i][curr_move] = max(dp[i][curr_move], dp[i-1][prev_move] + win_add);
                } else {
                    dp[i][curr_move] = max(dp[i][curr_move], dp[i-1][prev_move]);
                }
            }
        }
    }

    int max_wins = max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    cout << max_wins << endl;

    return 0;
}