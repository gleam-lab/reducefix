#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    int max_wins = 0;
    char current_move = beats[s[0]];
    max_wins = 1;

    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == current_move) {
            continue; // We keep winning with current move
        }
        if (s[i] == beats[current_move]) {
            // Opponent beats our current move, so we switch
            current_move = beats[s[i]];
            max_wins++;
        } else {
            // Our current move beats opponent's move, no need to switch
            continue;
        }
    }

    cout << max_wins << endl;

    return 0;
}