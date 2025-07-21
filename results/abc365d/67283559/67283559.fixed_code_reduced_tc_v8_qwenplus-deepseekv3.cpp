#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    // DP[i][c] represents the maximum score up to the i-th character with last move c.
    // c can be 'R', 'P', 'S' (Rock, Paper, Scissors).
    vector<unordered_map<char, int>> dp(N);

    // Initialize the first step.
    if (N >= 1) {
        char current = S[0];
        if (current == 'R') {
            dp[0]['P'] = 1; // Play Paper to beat Rock.
            dp[0]['R'] = 0;
            dp[0]['S'] = 0;
        } else if (current == 'P') {
            dp[0]['S'] = 1; // Play Scissors to beat Paper.
            dp[0]['P'] = 0;
            dp[0]['R'] = 0;
        } else if (current == 'S') {
            dp[0]['R'] = 1; // Play Rock to beat Scissors.
            dp[0]['S'] = 0;
            dp[0]['P'] = 0;
        }
    }

    for (int i = 1; i < N; ++i) {
        char current = S[i];
        // For each possible move we can play now (must be different from previous move).
        for (char prev_move : {'R', 'P', 'S'}) {
            if (dp[i-1].count(prev_move)) {
                for (char move : {'R', 'P', 'S'}) {
                    if (move != prev_move) {
                        int gain = 0;
                        if (move == 'R' && current == 'S') gain = 1;
                        else if (move == 'P' && current == 'R') gain = 1;
                        else if (move == 'S' && current == 'P') gain = 1;
                        if (dp[i].count(move)) {
                            dp[i][move] = max(dp[i][move], dp[i-1][prev_move] + gain);
                        } else {
                            dp[i][move] = dp[i-1][prev_move] + gain;
                        }
                    }
                }
            }
        }
    }

    int max_score = 0;
    if (N >= 1) {
        for (auto& entry : dp[N-1]) {
            max_score = max(max_score, entry.second);
        }
    }
    cout << max_score << endl;

    return 0;
}