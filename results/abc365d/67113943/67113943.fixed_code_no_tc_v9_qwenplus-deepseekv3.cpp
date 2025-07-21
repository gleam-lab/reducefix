#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    int wins = 0;
    char prev_move = '\0'; // Initialize to a null character

    for (char c : S) {
        char win_move;
        if (c == 'R') {
            win_move = 'P';
        } else if (c == 'P') {
            win_move = 'S';
        } else { // 'S'
            win_move = 'R';
        }

        if (win_move != prev_move) {
            wins++;
            prev_move = win_move;
        } else {
            // If the winning move is the same as the previous, we can't count it again
            // So, we reset the previous move to allow the next move to be counted
            prev_move = '\0';
        }
    }
    cout << wins << endl;
    return 0;
}