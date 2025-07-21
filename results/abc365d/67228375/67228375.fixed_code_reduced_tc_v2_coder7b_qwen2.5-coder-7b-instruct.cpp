#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Initialize variables to track the number of wins
    int wins = 0;
    char last_move = s[0];

    for (int i = 1; i < n; i++) {
        if (s[i] != last_move) {
            // If Aoki's move is not the same as the last one Takahashi moved, Takahashi wins
            wins++;
            // Update Takahashi's last move to the next optimal move based on Aoki's current move
            last_move = beats[s[i]];
        } else {
            // If Aoki's move is the same as the last one Takahashi moved, skip it and update last_move
            last_move = beats[last_move];
        }
    }

    // Since Takahashi always starts with an optimal move, we need to add 1 more win
    wins++;

    cout << wins << endl;

    return 0;
}