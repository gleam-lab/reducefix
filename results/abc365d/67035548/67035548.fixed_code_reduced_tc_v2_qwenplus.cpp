#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#include <iomanip>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X';
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    // dp[i][last] = max number of wins up to position i with last move being 'last'
    // We only need the previous state, so we can use two arrays.
    vector<int> prev_dp(3, 0); // Index: 0=R, 1=P, 2=S

    // Map char to index
    auto to_idx = [](char c) {
        if (c == 'R') return 0;
        if (c == 'P') return 1;
        if (c == 'S') return 2;
        return -1;
    };

    // Initial step: first character
    for (int j = 0; j < 3; j++) {
        char move = "RPS"[j];
        if (move == s[0]) {
            prev_dp[j] = 1; // We can stay with same move
        } else {
            prev_dp[j] = 0; // Not allowed to change on first move? Actually, we start fresh.
            // But note: we are allowed to choose any starting move. So no restriction.
            // However, opponent plays s[0], so if we play winning move, we get 1 point.
            // But wait: problem is about simulating a sequence where we react optimally?
            // Rethink: This is a known problem: maximize number of wins in rock-paper-scissors
            // against a fixed sequence, where you cannot repeat your own move consecutively.

            // Clarification from expected behavior:
            // Input: 4, PPRP -> Output: 3
            // How?
            // Opponent: P P R P
            // We can do: S P S R  -> Wins: S beats P, P ties P, S beats R, R beats P -> 3 wins.
            // But we cannot repeat our move: S then P (ok), P then S (ok), S then R (ok). Valid.

            // So we can choose any move at each step, as long as it's not same as previous.
            // And we get 1 point if our move beats opponent's move.
        }
    }

    // Actually, re-read the logic: we can pick any starting move.
    // So initialize all to 0, then update based on first round.
    for (int j = 0; j < 3; j++) {
        char our_move = "RPS"[j];
        char opp_move = s[0];
        prev_dp[j] = (win(opp_move) == our_move) ? 1 : 0;
    }

    // For each subsequent round
    for (int i = 1; i < n; i++) {
        vector<int> curr_dp(3, 0);
        char opp_move = s[i];

        for (int j = 0; j < 3; j++) { // current move
            char our_move = "RPS"[j];
            bool win_now = (win(opp_move) == our_move);
            int gain = win_now ? 1 : 0;

            for (int k = 0; k < 3; k++) { // previous move
                if (k == j) continue; // cannot repeat same move
                curr_dp[j] = max(curr_dp[j], prev_dp[k] + gain);
            }
        }
        prev_dp = curr_dp;
    }

    int ans = *max_element(prev_dp.begin(), prev_dp.end());
    cout << ans << endl;

    return 0;
}