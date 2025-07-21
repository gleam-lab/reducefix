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
    char prev_move = '\0';
    for (char c : S) {
        char current_win;
        if (c == 'R') {
            current_win = 'P';
        } else if (c == 'P') {
            current_win = 'S';
        } else if (c == 'S') {
            current_win = 'R';
        }
        if (current_win != prev_move) {
            wins++;
            prev_move = current_win;
        }
    }
    cout << wins;
    return 0;
}