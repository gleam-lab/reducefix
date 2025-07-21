#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to determine the winner between two moves
// Returns 1 if x beats y, -1 if y beats x, and 0 for draw
int cmp(char x, char y) {
    if (x == 'R') {
        if (y == 'S') return 1;
        if (y == 'P') return -1;
    } else if (x == 'P') {
        if (y == 'R') return 1;
        if (y == 'S') return -1;
    } else if (x == 'S') {
        if (y == 'P') return 1;
        if (y == 'R') return -1;
    }
    return 0;
}

// Function to return the winning move against a given move
char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // Should not happen
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int max_wins = 0;
    char last_move = 'X'; // Initially invalid move

    for (int i = 0; i < n; ++i) {
        char opponent_move = s[i];
        char my_move = win(opponent_move);

        // If we can continue with the current move
        if (cmp(my_move, opponent_move) == 1) {
            // We already have a winning move
            last_move = my_move;
        } else {
            // Need to change move to beat opponent
            max_wins++;
            last_move = my_move;
        }
    }

    cout << max_wins << endl;
    return 0;
}