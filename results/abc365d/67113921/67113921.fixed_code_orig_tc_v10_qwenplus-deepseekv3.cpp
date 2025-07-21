#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }

    int wins = 0;
    char prev = '\0';

    for (int i = 0; i < N; ++i) {
        char c = S[i];
        char winmove;
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else { // 'S'
            winmove = 'R';
        }

        if (winmove != prev) {
            wins++;
            prev = winmove;
        } else {
            // Check the next move to decide if we can switch
            if (i + 1 < N) {
                char next = S[i + 1];
                char next_winmove;
                if (next == 'R') {
                    next_winmove = 'P';
                } else if (next == 'P') {
                    next_winmove = 'S';
                } else { // 'S'
                    next_winmove = 'R';
                }
                if (next_winmove != winmove) {
                    prev = '\0'; // Reset to allow next move to be counted
                } else {
                    prev = c; // Skip this move
                }
            } else {
                prev = c; // Skip this move
            }
        }
    }

    cout << wins << endl;
    return 0;
}