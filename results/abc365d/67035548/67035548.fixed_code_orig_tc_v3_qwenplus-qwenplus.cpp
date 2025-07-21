#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Determine the outcome of a move against another
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
    return -100; // For invalid or placeholder
}

// Return the winning move for a given input
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

    // Forward pass: try to always play the winning move
    int ans = 0;
    char last_move = 'X'; // No move yet
    for (int i = 0; i < n; ++i) {
        char desired = win(s[i]);
        if (cmp(desired, last_move) > 0) {
            // Current move beats previous one, so we can keep the same
            last_move = desired;
            ans++;
        } else {
            // We need to change our move
            last_move = desired;
            ans++;
        }
    }

    // Backward pass: simulate optimal play from the end
    int sub = 0;
    last_move = 'X';
    for (int i = n - 1; i >= 0; --i) {
        char desired = win(s[i]);
        if (cmp(desired, last_move) > 0) {
            last_move = desired;
            sub++;
        } else {
            last_move = desired;
            sub++;
        }
    }

    cout << max(ans, sub) << endl;
}