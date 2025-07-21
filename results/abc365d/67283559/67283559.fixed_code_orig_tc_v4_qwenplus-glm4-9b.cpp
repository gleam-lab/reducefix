#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<char> hand = {'R', 'P', 'S'};
    int total = 0;

    // Precompute winning moves
    vector<char> winMove = {'S', 'R', 'P'};

    // First scenario: Always play the winning move
    for (int i = 0; i < N; ++i) {
        total += winMove[S[i] - 'R'];  // Convert 'R', 'P', 'S' to 0, 1, 2
    }

    // Second scenario: Play optimally based on the sequence
    int total2 = 0;
    vector<char> availableMoves = hand;  // Available moves to use next
    availableMoves.erase(find(availableMoves.begin(), availableMoves.end(), S[0]));  // Remove the move that was played first

    for (int i = 1; i < N; ++i) {
        int score = 0;
        char optimalMove = availableMoves[0];  // Assume the first available move is optimal
        for (char move : availableMoves) {
            if (winMove[move - 'R'] == S[i] - 'R') {
                score = 1;
                optimalMove = move;
                break;
            }
        }
        total2 += score;
        availableMoves.erase(find(availableMoves.begin(), availableMoves.end(), optimalMove));  // Remove the used move
    }

    cout << max(total, total2);
    return 0;
}