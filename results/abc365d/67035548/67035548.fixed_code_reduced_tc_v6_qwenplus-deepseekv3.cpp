#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    // DP table: dp[i][c] where c is the last move (0: R, 1: P, 2: S)
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));

    for (int i = 1; i <= n; ++i) {
        char current = s[i - 1];
        for (int last = 0; last < 3; ++last) {
            for (int curr_move = 0; curr_move < 3; ++curr_move) {
                char move_char;
                if (curr_move == 0) move_char = 'R';
                else if (curr_move == 1) move_char = 'P';
                else move_char = 'S';

                int win = 0;
                if (move_char == 'R' && current == 'S') win = 1;
                else if (move_char == 'P' && current == 'R') win = 1;
                else if (move_char == 'S' && current == 'P') win = 1;

                if (i == 1) {
                    dp[i][curr_move] = max(dp[i][curr_move], win);
                } else {
                    if (curr_move != last) {
                        dp[i][curr_move] = max(dp[i][curr_move], dp[i - 1][last] + win);
                    }
                }
            }
        }
    }

    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;

    return 0;
}