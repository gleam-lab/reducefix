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
    char prev = S[0]; // Initialize with the first move
    for (size_t i = 1; i < S.length(); ++i) { // Start from the second move
        char c = S[i];
        char winmove;
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else if (c == 'S') {
            winmove = 'R';
        }
        if (winmove != prev) {
            wins++;
            prev = winmove;
        } else {
            prev = c;
        }
    }
    cout << wins;

    return 0;
}