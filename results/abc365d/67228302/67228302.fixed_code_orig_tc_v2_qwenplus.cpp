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
            // Current opponent move is the same as our last winning move
            // We can continue using the same strategy
            continue;
        }
        else if (beats[s[i]] == last_move) {
            // Our last move still beats the current opponent move
            // So we don't need to change strategy
            last_move = s[i];
        }
        else {
            // We need to switch our move to beat the current opponent move
            last_move = beats[s[i]];
            total++;
        }
    }

    cout << total << endl;

    return 0;
}