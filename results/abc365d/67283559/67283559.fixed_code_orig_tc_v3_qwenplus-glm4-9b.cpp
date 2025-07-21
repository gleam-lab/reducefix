#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    vector<char> hand = {'R', 'P', 'S'};
    int total = 0;
    
    // Calculate the score for the sequence of the opponent's moves
    for (int i = 0; i < N; ++i) {
        char opponentMove = S[i];
        char optimalMove = ' ';
        int score = 0;

        for (char move : hand) {
            if ((move == 'R' && opponentMove == 'S') ||
                (move == 'P' && opponentMove == 'R') ||
                (move == 'S' && opponentMove == 'P')) {
                optimalMove = move;
                score = 1;
                break;
            }
        }

        // If no score was achieved, it means the optimal move was the same as the opponent's move
        if (score == 0) {
            optimalMove = opponentMove;
        }

        for (auto d : hand) {
            if (d != optimalMove) {
                cout << d;
            }
        }
        // Calculate total score
        total += score;

        // Remove the used move from the hand of the next possible moves
        hand.erase(remove(hand.begin(), hand.end(), optimalMove), hand.end());
    }

    // Output the total score
    cout << total << endl;
    
    return 0;
}