#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    int wins = 0;
    char prev_move = ' ';  // Track previous move made by the player

    for (char c : S) {
        char win_move;
        if (c == 'R') {
            win_move = 'P';
        } else if (c == 'P') {
            win_move = 'S';
        } else {  // c == 'S'
            win_move = 'R';
        }

        if (win_move != prev_move) {
            wins++;
            prev_move = win_move;
        } else {
            prev_move = c;  // Opponent played this, so we play c to not waste a move
        }
    }

    cout << wins << endl;
}