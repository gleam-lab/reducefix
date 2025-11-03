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

    int total = 1;
    char last_move = beats[s[0]];

    for (int i = 1; i < n; i++) {
        if (s[i] == last_move) {
            // Current move is same as what we played last time, so opponent's move will be same
            continue;
        } else if (beats[s[i]] == last_move) {
            // Opponent changed to beat our last move, so we keep playing the same
            last_move = s[i];
        } else {
            // We need to change our move to beat the new opponent move
            last_move = beats[s[i]];
            total++;
        }
    }

    cout << total << endl;

    return 0;
}