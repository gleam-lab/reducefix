#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;
    
    // Edge case: If there's only one character, it's already a win
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }

    int wins = 0;
    char winmove, prev = 'a';

    for (size_t i = 0; i < S.length(); ++i) {
        if (S[i] == 'R') {
            winmove = 'P';
        } else if (S[i] == 'P') {
            winmove = 'S';
        } else if (S[i] == 'S') {
            winmove = 'R';
        }

        // Check if the current move can beat the previous move
        if (winmove != prev && (winmove == 'R' || winmove == 'P' || winmove == 'S')) {
            wins++;
            prev = winmove;
        } else {
            prev = S[i];
        }
    }

    cout << wins << endl;
    return 0;
}