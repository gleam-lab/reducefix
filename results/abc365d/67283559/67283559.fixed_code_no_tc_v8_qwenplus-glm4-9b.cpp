#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int prevScore = 0;
    vector<char> prevHand = {'R', 'P', 'S'};
    int total = 0;

    // First pass to determine the optimal hand after the first element
    for (int i = 0; i < N; i++) {
        int score = 0;
        char bestMove = 'X'; // Default to invalid move
        for (char move : prevHand) {
            if ((move == 'R' && S[i] == 'S') ||
                (move == 'P' && S[i] == 'R') ||
                (move == 'S' && S[i] == 'P')) {
                score = 1;
                bestMove = move;
                break;
            }
        }

        // If no valid move is found, use the current element
        if (score == 0) {
            bestMove = S[i];
        }

        total += score;

        // Update the hand by removing the best move
        prevHand.erase(remove(prevHand.begin(), prevHand.end(), bestMove), prevHand.end());
    }

    int nextScore = 0;
    vector<char> nextHand = {'R', 'P', 'S'};
    int total2 = 0;

    // Second pass to determine the optimal hand after the second element
    for (int i = 1; i < N; i++) {
        int score = 0;
        char bestMove = 'X'; // Default to invalid move
        for (char move : nextHand) {
            if ((move == 'R' && S[i] == 'S') ||
                (move == 'P' && S[i] == 'R') ||
                (move == 'S' && S[i] == 'P')) {
                score = 1;
                bestMove = move;
                break;
            }
        }

        // If no valid move is found, use the current element
        if (score == 0) {
            bestMove = S[i];
        }

        total2 += score;

        // Update the hand by removing the best move
        nextHand.erase(remove(nextHand.begin(), nextHand.end(), bestMove), nextHand.end());
    }

    // Output the maximum score from the two passes
    cout << max(total, total2) << endl;

    return 0;
}