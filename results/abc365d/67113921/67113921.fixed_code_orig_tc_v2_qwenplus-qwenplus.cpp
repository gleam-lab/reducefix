#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    int wins = 0;
    char prev_move = 'a'; // Initially invalid to ensure first move is counted

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
        }
        // If already used the same winning move, opponent has changed strategy -> update to current move
        else {
            prev_move = c;
        }
    }

    cout << wins << endl;
}