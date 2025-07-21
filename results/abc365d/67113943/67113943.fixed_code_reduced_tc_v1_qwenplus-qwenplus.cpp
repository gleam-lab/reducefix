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
    char prev_move = 'a';  // Track the move we used in the previous round

    for (char c : S) {
        char current_win_move;
        if (c == 'R') {
            current_win_move = 'P';
        } else if (c == 'P') {
            current_win_move = 'S';
        } else {  // c == 'S'
            current_win_move = 'R';
        }

        // If our winning move is different from previous move, we can use it
        if (current_win_move != prev_move) {
            wins++;
            prev_move = current_win_move;
        } else {
            // We have to use the non-optimal move to avoid repeating our last move
            // This means we cannot win this round
            prev_move = c;  // Record the move we had to use
        }
    }

    cout << wins;

    return 0;
}