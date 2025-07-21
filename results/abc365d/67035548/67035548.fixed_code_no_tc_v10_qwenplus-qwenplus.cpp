#include <iostream>
#include <string>
using namespace std;

// Function to determine the winner between two moves
// Returns 1 if x beats y, -1 if y beats x, 0 if tie
int cmp(char x, char y) {
    if (x == 'P') {
        if (y == 'P') return 0;
        if (y == 'R') return 1;
        if (y == 'S') return -1;
    }
    if (x == 'R') {
        if (y == 'P') return -1;
        if (y == 'R') return 0;
        if (y == 'S') return 1;
    }
    if (x == 'S') {
        if (y == 'P') return 1;
        if (y == 'R') return -1;
        if (y == 'S') return 0;
    }
    return -100; // Invalid move
}

// Return the winning move against the given move
char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // Invalid move
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    // First pass: try to win from left to right
    int ans1 = 0;
    char prev = 'X'; // No move yet
    for (int i = 0; i < n; ++i) {
        char my_move = win(s[i]);
        if (cmp(my_move, prev) != 1) { // If this move doesn't beat previous opponent move
            ++ans1;
            prev = my_move;
        } else {
            prev = s[i]; // Opponent's move is same as previous, no change
        }
    }

    // Second pass: try to win from right to left
    int ans2 = 0;
    prev = 'X'; // Reset
    for (int i = n - 1; i >= 0; --i) {
        char my_move = win(s[i]);
        if (cmp(my_move, prev) != 1) { // If this move doesn't beat previous opponent move
            ++ans2;
            prev = my_move;
        } else {
            prev = s[i]; // Opponent's move is same as previous, no change
        }
    }

    cout << max(ans1, ans2) << endl;
    return 0;
}