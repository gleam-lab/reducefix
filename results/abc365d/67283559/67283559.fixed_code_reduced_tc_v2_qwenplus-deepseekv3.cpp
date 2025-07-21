#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    // Initialize DP: for each possible move, the maximum score up to the first round
    unordered_map<char, int> dp;
    dp['R'] = (S[0] == 'S') ? 1 : 0;
    dp['P'] = (S[0] == 'R') ? 1 : 0;
    dp['S'] = (S[0] == 'P') ? 1 : 0;
    
    for (int i = 1; i < N; ++i) {
        unordered_map<char, int> new_dp;
        // For each possible current move, find the best previous move that's different
        for (auto [current_move, _] : dp) {
            int best_prev = 0;
            for (auto [prev_move, prev_score] : dp) {
                if (prev_move != current_move) {
                    best_prev = max(best_prev, prev_score);
                }
            }
            int current_score = best_prev;
            if (current_move == 'R' && S[i] == 'S') current_score += 1;
            else if (current_move == 'P' && S[i] == 'R') current_score += 1;
            else if (current_move == 'S' && S[i] == 'P') current_score += 1;
            new_dp[current_move] = current_score;
        }
        dp = move(new_dp);
    }
    
    int max_score = 0;
    for (auto [_, score] : dp) {
        max_score = max(max_score, score);
    }
    cout << max_score << endl;
    
    return 0;
}