#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    int wins = 0;
    char prev_move = 'a';  // Track previous move of the player

    for (char c : S) {
        char winning_move;
        if (c == 'R') {
            winning_move = 'P';
        } else if (c == 'P') {
            winning_move = 'S';
        } else { // c == 'S'
            winning_move = 'R';
        }

        if (winning_move != prev_move) {
            wins++;
            prev_move = winning_move;
        } else {
            prev_move = c;  // Opponent played c, so we update to their move
        }
    }

    cout << wins << endl;
    return 0;
}