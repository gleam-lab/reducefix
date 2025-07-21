#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    int wins = 0;
    char prev_move = 'a';  // Track previous move of the player

    for (char c : S) {
        char winning_move;
        // Determine the winning move against opponent's current move
        if (c == 'R') winning_move = 'P';
        else if (c == 'P') winning_move = 'S';
        else winning_move = 'R';

        // If the winning move is different from previous move, win and update
        if (winning_move != prev_move) {
            wins++;
            prev_move = winning_move;
        } else {
            // Can't use same move twice in a row, so we have to play the opponent's move
            // This ensures we don't violate the constraint of no consecutive moves
            prev_move = c;  // We "play" their move this time
        }
    }

    cout << wins << endl;
    return 0;
}