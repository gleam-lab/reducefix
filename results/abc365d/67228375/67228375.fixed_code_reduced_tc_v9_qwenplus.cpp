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

    // dp[i][move] = maximum rounds won ending with move at position i
    // move: 0 for beats[s[i]], 1 for s[i], 2 for loses to s[i]
    auto getLoser = [](char c) {
        if (c == 'R') return 'S';
        if (c == 'P') return 'R';
        return 'P';
    };

    vector<array<int, 3>> dp(n);
    // 0: we play winning move against s[i] -> we win
    // 1: we play same move as s[i] -> draw
    // 2: we play losing move against s[i] -> lose
    
    dp[0][0] = 1; // play beats[s[0]] -> win
    dp[0][1] = 0; // play s[0] -> draw
    dp[0][2] = 0; // play loser -> lose

    for (int i = 1; i < n; i++) {
        char win_move = beats[s[i]];
        char same_move = s[i];
        char lose_move = getLoser(s[i]);

        // From previous state, we can transition based on what we played
        for (int prev = 0; prev < 3; prev++) {
            char prev_play;
            if (prev == 0) prev_play = beats[s[i-1]];
            else if (prev == 1) prev_play = s[i-1];
            else prev_play = getLoser(s[i-1]);

            // Current move options
            // Option 0: play win_move (beat opponent)
            if (win_move != prev_play) {
                dp[i][0] = max(dp[i][0], dp[i-1][prev] + 1);
            } else {
                dp[i][0] = max(dp[i][0], dp[i-1][prev] + 1); // still valid, just consecutive same
            }

            // Option 1: play same_move (draw)
            if (same_move != prev_play) {
                dp[i][1] = max(dp[i][1], dp[i-1][prev]);
            }

            // Option 2: play lose_move (lose)
            if (lose_move != prev_play) {
                dp[i][2] = max(dp[i][2], dp[i-1][prev]);
            }
        }
    }

    int result = max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    cout << result << endl;

    return 0;
}