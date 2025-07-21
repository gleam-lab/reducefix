#include <iostream>
#include <string>
using namespace std;

// Function to determine the winner between two moves
// Returns 1 if x beats y, -1 if x loses to y, 0 if draw
int cmp(char x, char y) {
    if (x == y) return 0;
    if ((x == 'R' && y == 'S') || (x == 'S' && y == 'P') || (x == 'P' && y == 'R'))
        return 1;
    return -1;
}

// Function to return the winning move against x
char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    return 'S';
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    char last_move = 'X'; // Initially set to an invalid character

    for (int i = 0; i < n; ++i) {
        char opponent_move = s[i];
        char current_move = win(opponent_move);

        // If we can use the same winning move as before
        if (cmp(current_move, last_move) == 0) {
            // It's still effective, no need to change strategy
            continue;
        } else {
            // We need to change our move to counter the opponent
            ans++;
            last_move = current_move;
        }
    }

    cout << ans << endl;
    return 0;
}