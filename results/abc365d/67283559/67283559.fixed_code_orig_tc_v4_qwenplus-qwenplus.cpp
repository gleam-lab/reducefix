#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;

    // We'll use dynamic programming to track the best score at each step
    // dp[i][c] = max score achievable up to i-th move ending with choice 'c'
    // where c can be 'R', 'P', or 'S'

    // Instead of using a full DP table which might take O(N) space,
    // we'll just keep track of the previous state to save space

    unordered_map<char, char> beats = {{'R', 'S'}, {'S', 'P'}, {'P', 'R'}};
    
    // Current available choices
    vector<char> choices = {'R', 'P', 'S'};
    
    // Initialize scores for the first move
    unordered_map<char, int> prev_scores;
    for (char c : choices) {
        if (beats[c] == S[0]) {
            prev_scores[c] = 1;  // Win
        } else {
            prev_scores[c] = 0;  // Not win
        }
    }

    // Start from the second move
    for (int i = 1; i < N; ++i) {
        unordered_map<char, int> curr_scores;
        for (char curr : choices) {
            // Find the max score from previous moves that don't include curr
            int max_score = 0;
            for (auto &[prev_char, score] : prev_scores) {
                if (prev_char != curr) {
                    max_score = max(max_score, score);
                }
            }
            // Add 1 if current move results in a win
            if (beats[curr] == S[i]) {
                max_score += 1;
            }
            curr_scores[curr] = max_score;
        }
        prev_scores = curr_scores;
    }

    // The answer is the maximum score among all possible last moves
    int result = 0;
    for (auto &[_, score] : prev_scores) {
        result = max(result, score);
    }

    cout << result << endl;
    return 0;
}