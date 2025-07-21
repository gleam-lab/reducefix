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
    char prev = 'a'; // previous move made by the bot

    for (char c : S) {
        char winmove;
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else { // c == 'S'
            winmove = 'R';
        }

        // If our winning move is different from the previous one, we make a change
        if (winmove != prev) {
            wins++;
            prev = winmove;
        } else {
            // We already played the winning move in the previous round,
            // so we continue with the same move
            prev = winmove;
        }
    }

    cout << wins << endl;
    return 0;
}