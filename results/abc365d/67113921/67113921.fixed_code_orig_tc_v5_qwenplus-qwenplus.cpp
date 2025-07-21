#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    int wins = 0;
    char prev_move = 'a'; // Initially invalid to allow first move

    for (char c : S) {
        char current_opponent_move = c;
        char current_winning_move;

        if (current_opponent_move == 'R') {
            current_winning_move = 'P';
        } else if (current_opponent_move == 'P') {
            current_winning_move = 'S';
        } else { // 'S'
            current_winning_move = 'R';
        }

        if (current_winning_move != prev_move) {
            wins++;
            prev_move = current_winning_move;
        } else {
            // We cannot win this round, so do not update prev_move or increment wins
            // But we have the option to play the opponent's move to reset for next round
            prev_move = current_opponent_move;
        }
    }

    cout << wins << endl;
}