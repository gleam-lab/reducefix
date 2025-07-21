#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Function to determine the outcome of a move against a previous move
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
    return -100; // For placeholder or invalid moves
}

// Function to return the winning move against a given move
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
    char last_move = 'X'; // Initially no move taken

    for (int i = 0; i < n; ++i) {
        char current = s[i];
        char best_response = win(current);

        // If we can play a new winning move, increase answer and update last move
        if (cmp(best_response, last_move) > 0) {
            ans++;
            last_move = best_response;
        } else {
            // Otherwise, opponent's move becomes our next move
            last_move = current;
        }
    }

    cout << ans << endl;
    return 0;
}