#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    // Define possible moves: Rock (R), Paper (P), Scissors (S)
    const vector<char> moves = {'R', 'P', 'S'};

    // Initialize scores and variables
    int totalScore = 0;
    char currentMove = S[0];

    // Iterate through each character in the string
    for (int i = 0; i < N; ++i) {
        int score = 0;
        for (char move : moves) {
            if ((move == 'R' && S[i] == 'S') ||
                (move == 'P' && S[i] == 'R') ||
                (move == 'S' && S[i] == 'P')) {
                score++;
                currentMove = move;
                break;
            }
        }
        totalScore += score;
    }

    // Reset moves and prepare for the second part of the logic
    moves.clear();

    // Add all moves except the first one used in the previous iteration
    for (char move : {'R', 'P', 'S'}) {
        if (move != currentMove) {
            moves.push_back(move);
        }
    }

    // Reinitialize scores and variables for the second part
    int totalScore2 = 0;
    currentMove = S[0];

    // Repeat the same process for the second part
    for (int i = 1; i < N; ++i) {
        int score = 0;
        for (char move : moves) {
            if ((move == 'R' && S[i] == 'S') ||
                (move == 'P' && S[i] == 'R') ||
                (move == 'S' && S[i] == 'P')) {
                score++;
                currentMove = move;
                break;
            }
        }
        totalScore2 += score;
    }

    // Output the maximum score between the two parts
    cout << max(totalScore, totalScore2);

    return 0;
}