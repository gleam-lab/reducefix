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
    char prev = ' '; // Use space or any non-move char as initial state

    for (char c : S) {
        char winmove;
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else { // c == 'S'
            winmove = 'R';
        }

        if (winmove != prev) {
            wins++;
            prev = winmove;
        } else {
            // We cannot use the same move, so we must use the current move's counter move
            // But since we already lost in this case, we just update prev to current move
            prev = c;
        }
    }

    cout << wins << endl;
    return 0;
}