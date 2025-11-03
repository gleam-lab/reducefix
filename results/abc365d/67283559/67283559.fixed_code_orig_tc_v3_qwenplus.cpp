#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;

    // Rock beats Scissors, Paper beats Rock, Scissors beats Paper
    auto wins = [](char a, char b) {
        return (a == 'R' && b == 'S') ||
               (a == 'P' && b == 'R') ||
               (a == 'S' && b == 'P');
    };

    // We can choose any starting move.
    // After each round, we must avoid the move we used (so two choices remain).
    // However, we are allowed to pick optimally among remaining moves.

    // Instead of simulating all possibilities, we use DP:
    // Let dp[i][c] = maximum score we can achieve up to position i ending with move c.
    // But note: at step i, we cannot use the same move as step i-1.
    // Actually, the rule is: we cannot use the same move twice consecutively? 
    // No: the problem says after using a move, that move is "exhausted" for next round.
    // So we have: at step 0: can use R, P, or S.
    // At step i (i>=1): we can use any move except the one used at step i-1.

    // Therefore, state: dp[i][last] = max score from 0..i where last move was `last`
    // last in {0,1,2} representing R,P,S

    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<array<int, 3>> dp(N, {array<int,3>{-1,-1,-1}});
    // Initialize first move
    for (int j = 0; j < 3; j++) {
        char my_move = "RPS"[j];
        dp[0][j] = wins(my_move, S[0]) ? 1 : 0;
    }

    for (int i = 1; i < N; i++) {
        for (int prev = 0; prev < 3; prev++) {
            if (dp[i-1][prev] == -1) continue;
            // From state with last move = prev, we can choose any move except prev
            for (int curr = 0; curr < 3; curr++) {
                if (curr == prev) continue;
                char my_move = "RPS"[curr];
                char opp_move = S[i];
                int score = dp[i-1][prev] + (wins(my_move, opp_move) ? 1 : 0);
                if (score > dp[i][curr]) {
                    dp[i][curr] = score;
                }
            }
        }
    }

    int result = *max_element(dp[N-1].begin(), dp[N-1].end());
    cout << result << endl;

    return 0;
}