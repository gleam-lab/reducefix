#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string S;
    cin >> S;

    // hand: all possible moves
    vector<char> hand = {'R', 'P', 'S'};
    
    // dp[i][c]: max wins up to i-th round ending with move c
    map<char, int> dp;

    for (int i = 0; i < N; ++i) {
        map<char, int> new_dp;
        for (char play : hand) {
            int best = 0;
            for (char prev : hand) {
                if (prev == play) continue; // not allowed

                // Check win condition
                if ((play == 'R' && S[i] == 'S') ||
                    (play == 'P' && S[i] == 'R') ||
                    (play == 'S' && S[i] == 'P')) {
                    best = max(best, dp[prev] + 1);
                } else {
                    best = max(best, dp[prev]);
                }
            }
            new_dp[play] = best;
        }
        dp = new_dp;
    }

    cout << max({dp['R'], dp['P'], dp['S']}) << endl;
}