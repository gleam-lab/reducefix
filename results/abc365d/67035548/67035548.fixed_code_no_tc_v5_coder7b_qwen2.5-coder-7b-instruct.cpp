#include <iostream>
#include <string>

using namespace std;

// Function to determine the winning move for a given move
char getWinningMove(char move) {
    switch(move) {
        case 'R': return 'P';
        case 'P': return 'S';
        case 'S': return 'R';
        default: return 'X'; // This should not happen with valid inputs
    }
}

// Function to determine the losing move for a given move
char getLosingMove(char move) {
    switch(move) {
        case 'R': return 'S';
        case 'P': return 'R';
        case 'S': return 'P';
        default: return 'X'; // This should not happen with valid inputs
    }
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    // Initialize variables to track the best possible wins
    int maxWins = 0;
    char lastMove = 'X';

    // Iterate through each move in the sequence
    for (int i = 0; i < n; ++i) {
        char currentMove = s[i];

        // If the current move is different from the last move or it's the first move
        if (i == 0 || currentMove != lastMove) {
            // Increment the count of wins
            maxWins++;
            // Update the last move to the current move's winning move
            lastMove = getWinningMove(currentMove);
        }
    }

    // Print the maximum number of wins
    cout << maxWins << endl;

    return 0;
}