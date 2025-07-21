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
    char prev_move = ' '; // No move initially

    for (char c : S) {
        char win_move;
        if (c == 'R') {
            win_move = 'P';
        } else if (c == 'P') {
            win_move = 'S';
        } else { // c == 'S'
            win_move = 'R';
        }

        if (win_move != prev_move) {
            wins++;
            prev_move = win_move;
        } else {
            // We cannot win this round, so we play the same as opponent to not reveal our strategy
            prev_move = c; // Not used for winning, but keeps the logic consistent
        }
    }

    cout << wins << endl;
}