#include <iostream>
#include <string>
using namespace std;

// Function to determine the winner of a single round
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
    return 0; // Should not reach here
}

// Function to return the winning move against a given move
char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // Invalid case
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    char prev_move = 'X'; // No previous move at start

    for (int i = 0; i < n; ++i) {
        char current_opponent = s[i];
        char current_strategy = win(current_opponent);

        // If we can use the same move as before, do so (no need to change)
        // Otherwise, we must change our move
        if (prev_move != current_strategy) {
            ans++;
            prev_move = current_strategy;
        }
    }

    cout << ans << endl;
    return 0;
}