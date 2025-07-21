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
    char prev_move = 'a'; // No move before the first round

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
            // We must choose a different move that doesn't match previous
            // Choose any move that is not equal to c and not equal to prev_move
            if (c == 'R') {
                if (prev_move != 'R') {
                    prev_move = 'R';
                } else {
                    prev_move = 'S'; // or 'R' again, but already counted
                }
            } else if (c == 'P') {
                if (prev_move != 'S') {
                    prev_move = 'S';
                } else {
                    prev_move = 'R';
                }
            } else { // c == 'S'
                if (prev_move != 'R') {
                    prev_move = 'R';
                } else {
                    prev_move = 'P';
                }
            }
        }
    }

    cout << wins;
    return 0;
}