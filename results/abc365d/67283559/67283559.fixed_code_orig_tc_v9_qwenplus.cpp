#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;

    // Define the winning moves
    auto wins = [](char a, char b) -> bool {
        return (a == 'R' && b == 'S') ||
               (a == 'P' && b == 'R') ||
               (a == 'S' && b == 'P');
    };

    // We simulate the tournament elimination process
    // At each round, we decide which hand to use based on future information
    // However, optimal strategy: at each step, choose a move that beats opponent if possible,
    // otherwise choose the same as opponent to survive

    vector<char> candidates = {'R', 'P', 'S'};
    int total_score = 0;

    for (int i = 0; i < N; i++) {
        vector<char> next_candidates;
        char best_move = 0;
        int max_future_survival = -1;

        // Try each possible move
        for (char move : candidates) {
            if (wins(move, S[i])) {
                // We win this round
                total_score++;
                // For next round, remove the move we just used
                for (char c : {'R', 'P', 'S'}) {
                    if (c != move) {
                        next_candidates.push_back(c);
                    }
                }
                candidates = next_candidates;
                break;
            }
        }

        // If no winning move was found
        if (next_candidates.empty()) {
            // We must survive by playing the same move as opponent
            // But we still have choices among the remaining candidates
            for (char move : candidates) {
                if (move == S[i]) {
                    // This move will survive
                    best_move = move;
                    break;
                }
            }
            // If we can't play the same move, pick any
            if (!best_move) {
                best_move = candidates[0];
            }

            // Update candidates for next round
            next_candidates.clear();
            for (char c : {'R', 'P', 'S'}) {
                if (c != best_move) {
                    next_candidates.push_back(c);
                }
            }
            candidates = next_candidates;
        }
    }

    cout << total_score << endl;
    return 0;
}