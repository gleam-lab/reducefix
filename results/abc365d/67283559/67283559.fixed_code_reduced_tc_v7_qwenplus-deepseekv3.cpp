#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    if (N == 0) {
        cout << 0;
        return 0;
    }

    // DP table: dp[i][c] represents the maximum wins up to the i-th round ending with move c
    // c can be 'R', 'P', 'S'
    vector<vector<int>> dp(N, vector<int>(3, 0));

    // Initialize the first round
    for (int c = 0; c < 3; ++c) {
        char move;
        if (c == 0) move = 'R';
        else if (c == 1) move = 'P';
        else move = 'S';

        if (move == 'R' && S[0] == 'S') dp[0][c] = 1;
        else if (move == 'P' && S[0] == 'R') dp[0][c] = 1;
        else if (move == 'S' && S[0] == 'P') dp[0][c] = 1;
        else dp[0][c] = 0;
    }

    for (int i = 1; i < N; ++i) {
        for (int c = 0; c < 3; ++c) {
            char current_move;
            if (c == 0) current_move = 'R';
            else if (c == 1) current_move = 'P';
            else current_move = 'S';

            int current_win = 0;
            if (current_move == 'R' && S[i] == 'S') current_win = 1;
            else if (current_move == 'P' && S[i] == 'R') current_win = 1;
            else if (current_move == 'S' && S[i] == 'P') current_win = 1;

            // The previous move cannot be the same as current_move
            for (int prev_c = 0; prev_c < 3; ++prev_c) {
                if (prev_c == c) continue;
                dp[i][c] = max(dp[i][c], dp[i - 1][prev_c] + current_win);
            }
        }
    }

    int max_wins = 0;
    for (int c = 0; c < 3; ++c) {
        max_wins = max(max_wins, dp[N - 1][c]);
    }

    cout << max_wins;
    return 0;
}