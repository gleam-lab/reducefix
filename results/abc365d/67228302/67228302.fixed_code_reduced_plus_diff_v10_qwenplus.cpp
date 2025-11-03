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
    char last_win = beats[s[0]]; // what would beat the first move

    for (int i = 1; i < n; i++) {
        char current_beats = beats[s[i]];
        // If the current winning move is different from the last one,
        // we need a new round
        if (current_beats != last_win) {
            total++;
            last_win = current_beats;
        }
    }

    cout << total << endl;

    return 0;
}