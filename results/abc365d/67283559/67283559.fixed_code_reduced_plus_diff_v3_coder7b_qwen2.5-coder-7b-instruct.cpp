#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    string S;
    cin >> S;

    // Define winning moves
    const vector<char> wins{'R', 'P', 'S'};

    // Initialize scores and choices
    vector<int> scores(3, 0);
    vector<char> choices{'R', 'P', 'S'};

    // Function to determine the best move
    auto getBestMove = [&](char opponent) -> char {
        for (char win : wins) {
            if ((win == 'R' && opponent == 'S') ||
                (win == 'P' && opponent == 'R') ||
                (win == 'S' && opponent == 'P')) {
                return win;
            }
        }
        return opponent; // In case of no clear winner, choose the same as opponent
    };

    // First phase: Calculate scores and remaining choices
    for (int i = 0; i < N; ++i) {
        char current = S[i];
        for (size_t j = 0; j < choices.size(); ++j) {
            if (choices[j] != current) {
                scores[j]++;
            }
        }
        choices.erase(remove(choices.begin(), choices.end(), current), choices.end());
    }

    // Second phase: Determine the final answer
    int bestScore = 0;
    for (char choice : choices) {
        int score = 0;
        for (int i = 0; i < N; ++i) {
            if (choice == S[i]) continue;
            char bestChoice = getBestMove(S[i]);
            if (bestChoice == choice) {
                score++;
            }
        }
        bestScore = max(bestScore, score);
    }

    cout << bestScore << '\n';

    return 0;
}