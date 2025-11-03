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
        // If current opponent's move beats our last move, we must change strategy
        if (beats[s[i]] == last_move) {
            // Our previous winning move is now losing, so we need to switch
            last_move = beats[s[i]];
            total++;
        }
        // Otherwise, our last move still beats the current opponent move, so we keep it
        // No need to change strategy
    }

    cout << total << endl;
    return 0;
}