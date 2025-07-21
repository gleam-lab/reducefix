#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    string hand = "RP";
    int totalScore = 0;

    for (int i = 0; i < N; ++i) {
        int score = 0;
        char optimalMove = ' ';

        // Determine the optimal move for the current player
        if (S[i] == 'R') {
            optimalMove = 'P';
        } else if (S[i] == 'P') {
            optimalMove = 'S';
        } else if (S[i] == 'S') {
            optimalMove = 'R';
        }

        // Simulate the game
        for (char move : hand) {
            if (move == optimalMove) {
                ++score;
            }
        }
        totalScore += score;
        hand = string(1, optimalMove); // Update the hand to only include the next move
    }

    cout << totalScore;
    return 0;
}