#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 100007

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
    char last_winner = beats[s[0]];

    for (int i = 1; i < n; i++) {
        // If current move beats the previous winner, then new round starts
        if (s[i] == last_winner) {
            // Current player wins again, continue same round
            continue;
        }
        else if (beats[s[i]] == last_winner) {
            // Previous winner still beats current move, so current move loses
            // Round continues with same winner
            continue;
        }
        else {
            // Current move beats the last winner -> new round begins
            last_winner = beats[s[i]];
            total++;
        }
    }

    cout << total << endl;

    return 0;
}