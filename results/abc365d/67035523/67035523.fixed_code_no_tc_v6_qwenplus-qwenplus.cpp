#include <iostream>
#include <string>
using namespace std;

// Function to determine the winner of a round
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
    return -100; // Placeholder case (should not occur)
}

// Function to return the winning move against a given move
char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // Shouldn't happen for valid input
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    char last_move = 'X'; // No move yet

    for (int i = 0; i < n; ++i) {
        char opponent_move = s[i];
        char my_move = win(opponent_move);

        // Check if we can reuse the same move as before
        if (last_move != my_move) {
            ans++;
            last_move = my_move;
        } else {
            // Can't repeat the same move, need to pick an alternative
            // Choose any move that still beats opponent (if possible)
            // Or pick any valid move and increment change count
            // This depends on game rules for move restrictions
            // Assuming we must change move if repeated
            // So we need to find an alternate winning strategy

            // Brute-force try all options to find a valid move that beats opponent
            bool found = false;
            char alt_moves[3] = {'R', 'S', 'P'};
            for (int j = 0; j < 3; ++j) {
                if (cmp(alt_moves[j], opponent_move) == 1 && alt_moves[j] != last_move) {
                    last_move = alt_moves[j];
                    found = true;
                    break;
                }
            }

            if (!found) {
                // If no other move works, we must change move and accept the penalty
                // Pick any different move that beats or at least changes
                for (int j = 0; j < 3; ++j) {
                    if (alt_moves[j] != last_move && cmp(alt_moves[j], opponent_move) >= 0) {
                        last_move = alt_moves[j];
                        ans++;
                        break;
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}