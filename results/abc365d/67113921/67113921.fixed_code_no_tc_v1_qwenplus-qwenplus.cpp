#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    int wins = 0;
    char last_move = 'a';  // Track the last move we made

    for (char c : S) {
        char counter_move;
        if (c == 'R') counter_move = 'P';
        else if (c == 'P') counter_move = 'S';
        else counter_move = 'R';

        if (counter_move != last_move) {
            wins++;
            last_move = counter_move;
        } else {
            // We can't use the same move, so we have to use the losing move
            last_move = c;  // This is just to track what the opponent played, not our move
        }
    }

    cout << wins << endl;
    return 0;
}