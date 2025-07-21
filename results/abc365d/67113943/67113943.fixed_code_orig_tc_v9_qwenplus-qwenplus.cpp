#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    int wins = 0;
    char prev_move = 'a'; // previous move played by us

    for (char c : S) {
        char win_move;
        if (c == 'R') win_move = 'P';
        else if (c == 'P') win_move = 'S';
        else win_move = 'R';

        if (win_move != prev_move) {
            wins++;
            prev_move = win_move;
        } else {
            // We have to change our move to avoid repetition
            // Try another winning move if possible, otherwise pick any non-repeating move
            char alt_win_move = win_move;
            if (win_move == 'R') alt_win_move = 'S';
            else if (win_move == 'P') alt_win_move = 'R';
            else alt_win_move = 'P';

            if (alt_win_move != prev_move) {
                wins++;
                prev_move = alt_win_move;
            } else {
                // Cannot win this round without repeating
                prev_move = c; // we play something different but non-winning
            }
        }
    }

    cout << wins << endl;
    return 0;
}