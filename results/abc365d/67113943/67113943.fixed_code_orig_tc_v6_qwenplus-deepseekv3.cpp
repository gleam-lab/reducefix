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
        char move;
        if (c == 'R') {
            move = 'P';
        } else if (c == 'P') {
            move = 'S';
        } else { // 'S'
            move = 'R';
        }

        if (move != prev_move) {
            wins++;
            prev_move = move;
        } else {
            // To maximize wins, we can sometimes choose a different move that also beats the next character
            // Reset prev_move to allow the next character to choose optimally
            prev_move = '\0';
        }
    }

    cout << wins << '\n';
    return 0;
}