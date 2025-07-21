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
    char last_move = 'a';  // Track the last move we played

    for (char c : S) {
        char our_move;
        // Determine the move that beats the opponent's move
        if (c == 'R') {
            our_move = 'P';
        } else if (c == 'P') {
            our_move = 'S';
        } else { // c == 'S'
            our_move = 'R';
        }

        // If our move is different from the previous one, it's a valid move change
        if (our_move != last_move) {
            wins++;
            last_move = our_move;
        }
        // Else, we keep the same move as before (no increment)
    }

    cout << wins << endl;
    return 0;
}