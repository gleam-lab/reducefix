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
    char prev_move = 'a'; // previous move we played, not the opponent's

    for (char opponent_move : S) {
        char current_win_move;
        if (opponent_move == 'R') {
            current_win_move = 'P';
        } else if (opponent_move == 'P') {
            current_win_move = 'S';
        } else { // S
            current_win_move = 'R';
        }

        if (current_win_move != prev_move) {
            wins++;
            prev_move = current_win_move;
        } else {
            // We must have tied the previous round, so update prev_move to what the opponent did
            prev_move = opponent_move;
        }
    }

    cout << wins << endl;
    return 0;
}