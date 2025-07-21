#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Function to determine the outcome of a move against previous move
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
    return -100; // For placeholder or invalid characters
}

// Function to return the winning move for a given move
char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // Placeholder
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    char last_move = 'X'; // Placeholder to start with no move

    for (char c : s) {
        char best_move = win(c);
        if (last_move != best_move) {
            ans++;
            last_move = best_move;
        } else {
            // If we can't play the same move again, just alternate strategy
            // However, in this optimal scenario, we assume we can always choose the winning move
            // So we only increment when the move changes
            last_move = best_move;
        }
    }

    cout << ans << endl;
    return 0;
}