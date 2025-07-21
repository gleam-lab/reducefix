#include <iostream>
#include <string>
using namespace std;

// Determine the outcome of a match between two moves
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
    return -100; // Placeholder for invalid move
}

// Return the winning move against given move
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
    char last_move = 'X'; // No move initially

    for (int i = 0; i < n; ++i) {
        char opponent_move = s[i];
        char my_move = win(opponent_move);

        // If the current move is same as previous, we need to change it
        if (my_move == last_move) {
            // Opponent's move changes, so pick a different move
            // We can just increment the answer since the actual move doesn't matter
            ans++;
            // Choose a move that beats a different option (not necessary to compute exact)
            // Just ensure it's different from last move
            last_move = (my_move == 'P') ? 'R' : ((my_move == 'R') ? 'S' : 'P');
        } else {
            last_move = my_move;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}