#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    int wins = 0;
    char last_move = 'X'; // No previous move initially

    for (char c : S) {
        char winmove;
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else { // c == 'S'
            winmove = 'R';
        }

        // We can use the winning move unless it was used in the previous round
        if (winmove != last_move) {
            wins++;
            last_move = winmove;
        } else {
            // If our winning move was used last time, we must pick a different one
            // But we still want to win if possible with another option
            // However, only one move beats a given move
            // So if our winning move is blocked, we cannot win this round
            // So we play either of the other two moves (one loses, one ties), but result is not a win
            // So we just update last_move to something different from previous
            // Pick any move except last_move. Doesn't matter for future as long as it's recorded.
            if (winmove == 'R') {
                last_move = 'P'; // could also be 'S', but 'P' is safe since it's not 'R'
            } else if (winmove == 'P') {
                last_move = 'S';
            } else { // winmove == 'S'
                last_move = 'R';
            }
            // No win in this case
        }
    }

    cout << wins;
}