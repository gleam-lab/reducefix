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
    return 0;
}

// Function to get the winning move against a given move
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

    // Forward pass: try to win from left to right
    int ans1 = 1;
    char last_move = win(s[0]);
    for (int i = 1; i < n; ++i) {
        char best_move = win(s[i]);
        if (cmp(best_move, s[i]) > 0 && best_move != last_move) {
            ++ans1;
            last_move = best_move;
        } else {
            last_move = s[i]; // Opponent's move if we can't play a new winning move
        }
    }

    // Backward pass: try to win from right to left
    int ans2 = 1;
    last_move = win(s[n-1]);
    for (int i = n-2; i >= 0; --i) {
        char best_move = win(s[i]);
        if (cmp(best_move, s[i]) > 0 && best_move != last_move) {
            ++ans2;
            last_move = best_move;
        } else {
            last_move = s[i]; // Opponent's move if we can't play a new winning move
        }
    }

    cout << max(ans1, ans2) << endl;
    return 0;
}