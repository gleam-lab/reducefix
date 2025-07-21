#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    int wins = 0;
    char prev_move = '\0';

    for (char c : S) {
        char current_move;
        if (c == 'R') {
            current_move = 'P';
        } else if (c == 'P') {
            current_move = 'S';
        } else { // 'S'
            current_move = 'R';
        }

        if (current_move != prev_move) {
            wins++;
            prev_move = current_move;
        } else {
            // Check the next character to decide if we can keep the same move
            // This part is tricky; the initial approach didn't handle it optimally
            // For simplicity, reset prev_move to allow the next move to be current_move again
            prev_move = '\0';
        }
    }

    cout << wins << endl;
    return 0;
}