#include <iostream>
#include <string>
using namespace std;

// Function to determine the winner between two moves
// Returns 1 if x beats y, -1 if x loses to y, 0 if draw
int cmp(char x, char y) {
    if (x == 'P') {
        if (y == 'P') return 0;
        if (y == 'R') return 1; // Paper beats Rock
        if (y == 'S') return -1; // Paper loses to Scissors
    }
    if (x == 'R') {
        if (y == 'P') return -1; // Rock loses to Paper
        if (y == 'R') return 0;
        if (y == 'S') return 1; // Rock beats Scissors
    }
    if (x == 'S') {
        if (y == 'P') return 1; // Scissors beats Paper
        if (y == 'R') return -1; // Scissors loses to Rock
        if (y == 'S') return 0;
    }
    return 0; // Should not reach here
}

// Function to return the winning move against x
char win(char x) {
    if (x == 'R') return 'P'; // Paper beats Rock
    if (x == 'S') return 'R'; // Rock beats Scissors
    if (x == 'P') return 'S'; // Scissors beats Paper
    return 'X'; // Invalid input
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    char last_move = 'X'; // No move yet

    for (int i = 0; i < n; ++i) {
        char opponent_move = s[i];
        char my_move = win(opponent_move); // What I need to play to win

        // Check if we can use the same move as before
        if (last_move != my_move) {
            ans++; // Need to change hand signal
            last_move = my_move;
        }
    }

    cout << ans << endl;
    return 0;
}