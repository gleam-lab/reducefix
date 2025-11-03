#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    int wins = 0;
    char last_move = ' '; // No move initially

    for (char c : S) {
        char winmove;
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else { // c == 'S'
            winmove = 'R';
        }

        // If we can use the winning move again, reuse it
        if (last_move != winmove) {
            wins++;
            last_move = winmove;
        } else {
            // We already used this winning move, so now we are forced to "lose" or tie
            // But we can still set our move to the opponent's current move to potentially break future ties
            last_move = c;
        }
    }

    cout << wins;
}