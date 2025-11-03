#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string S;
    cin >> S;

    // Rock beats Scissors, Paper beats Rock, Scissors beats Paper
    auto wins = [](char a, char b) -> bool {
        return (a == 'R' && b == 'S') ||
               (a == 'P' && b == 'R') ||
               (a == 'S' && b == 'P');
    };

    // For each starting choice, simulate the game
    vector<char> choices = {'R', 'P', 'S'};
    int max_score = 0;

    for (char first_choice : choices) {
        int score = 0;
        char current_choice = first_choice;

        for (int i = 0; i < N; i++) {
            if (wins(current_choice, S[i])) {
                score++;
            }
            // Update available choices: remove the one we just used
            vector<char> next_choices;
            for (char c : choices) {
                if (c != current_choice) {
                    next_choices.push_back(c);
                }
            }
            // Choose the best option from remaining two for next round
            char best_next = next_choices[0];
            for (char c : next_choices) {
                // Prefer the one that can potentially win in future
                if (next_choices.size() == 2) {
                    // If both are available, pick the one that beats the opponent's next move (if known)
                    // Otherwise use a consistent strategy
                    if (i + 1 < N && wins(c, S[i+1]) && !wins(best_next, S[i+1])) {
                        best_next = c;
                    }
                } else {
                    best_next = c;
                }
            }
            current_choice = best_next;
        }
        max_score = max(max_score, score);
    }

    cout << max_score << endl;
    return 0;
}