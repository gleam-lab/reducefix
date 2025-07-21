#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    int wins = 0;
    char prev_move = 'a'; // track the previous move we made

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
            // We can't use the same winning move again, so we must choose a different move.
            // To maximize wins, we should reset our move to something different than last round's move,
            // but still ensure it doesn't conflict with the next opponent's move in the future.
            // However, since this is greedy, we can just pick any different move than last time.
            // Here we arbitrarily choose to switch to the move that beats opponent's current move.
            // But only if it's different from previous move.
            if (win_move == prev_move) {
                // try another winning option
                if (c == 'R') {
                    win_move = 'S'; // not optimal but needed for unique choice
                }
                // update prev_move accordingly
                prev_move = win_move;
            } else {
                prev_move = c; // opponent's move becomes our new previous move
            }
        }
    }

    cout << wins << endl;
}