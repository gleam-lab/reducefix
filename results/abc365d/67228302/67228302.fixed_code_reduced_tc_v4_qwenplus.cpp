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
    char last_win = beats[s[0]]; // What we played to beat the first move

    for (int i = 1; i < n; i++) {
        char current_beat = beats[s[i]];
        // If our previous winning move also beats current opponent move
        if (beats[last_win] == s[i]) {
            // We don't need to change our move
            continue;
        } else {
            // We need to switch our move to beat current opponent move
            last_win = current_beat;
            total++;
        }
    }

    cout << total << endl;

    return 0;
}