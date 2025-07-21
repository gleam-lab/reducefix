#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char get_winning_move(char c) {
    if (c == 'R') return 'P';
    if (c == 'P') return 'S';
    if (c == 'S') return 'R';
    return ' ';
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    // DP[i][0] = max wins up to i-th character when last move is R
    // DP[i][1] = max wins up to i-th character when last move is P
    // DP[i][2] = max wins up to i-th character when last move is S
    vector<vector<int>> dp(n, vector<int>(3, 0));

    // Initialize the first step
    char winning_move = get_winning_move(s[0]);
    if (winning_move == 'R') {
        dp[0][0] = 1;
        dp[0][1] = 0;
        dp[0][2] = 0;
    } else if (winning_move == 'P') {
        dp[0][0] = 0;
        dp[0][1] = 1;
        dp[0][2] = 0;
    } else if (winning_move == 'S') {
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = 1;
    }

    for (int i = 1; i < n; ++i) {
        char current_win = get_winning_move(s[i]);
        int add_r = (current_win == 'R') ? 1 : 0;
        int add_p = (current_win == 'P') ? 1 : 0;
        int add_s = (current_win == 'S') ? 1 : 0;

        // Transition from previous R, P, S to current R
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + add_r;
        // Transition from previous R, P, S to current P
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + add_p;
        // Transition from previous R, P, S to current S
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + add_s;
    }

    int max_wins = max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    cout << max_wins << endl;

    return 0;
}