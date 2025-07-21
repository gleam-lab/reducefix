#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    int wins = 0;
    char prev_move = ' ';  // Use a value that can't be in the input

    for (char c : S) {
        char win_move;
        if (c == 'R') win_move = 'P';
        else if (c == 'P') win_move = 'S';
        else win_move = 'R';  // c == 'S'

        if (win_move != prev_move) {
            wins++;
            prev_move = win_move;
        } else {
            prev_move = c;  // We have to play c to avoid repetition
        }
    }

    cout << wins << endl;
}