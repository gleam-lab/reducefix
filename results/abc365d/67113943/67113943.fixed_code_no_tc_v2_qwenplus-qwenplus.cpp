#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;

    int wins = 0;
    char opponent_move, my_move;

    // Initialize previous move as something that won't match first move
    char prev_my_move = 'X'; 

    for (char c : S) {
        // Determine the move that would beat the opponent's move
        if (c == 'R') {
            my_move = 'P';
        } else if (c == 'P') {
            my_move = 'S';
        } else { // c == 'S'
            my_move = 'R';
        }

        // If the winning move is different from the previous move, play it
        if (my_move != prev_my_move) {
            wins++;
            prev_my_move = my_move;
        } else {
            // We already played this move in the previous round, so we cannot win this round
            // Just update previous move to current opponent's move (or anything different)
            prev_my_move = c; 
        }
    }

    cout << wins << endl;
    return 0;
}