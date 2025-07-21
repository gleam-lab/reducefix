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
            // Check if we can change the move to win the next one as well
            if (i + 1 < N) {
                char next = S[i + 1];
                char nextwinmove;
                if (next == 'R') {
                    nextwinmove = 'P';
                } else if (next == 'P') {
                    nextwinmove = 'S';
                } else { // 'S'
                    nextwinmove = 'R';
                }
                if (nextwinmove != winmove) {
                    prev = nextwinmove;
                } else {
                    prev = c; // Stick to the current move
                }
            }
        }
    }
    cout << wins << endl;
    return 0;
}