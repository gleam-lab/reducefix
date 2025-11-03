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
    char last_move = s[0];

    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move) {
            // Current move beats the last winning move, so chain continues with current move as winner
            last_move = s[i];
        } else if (s[i] != last_move) {
            // Current move doesn't beat or equal last move, so new round starts
            total++;
            last_move = s[i];
        }
        // If s[i] == last_move, same winner continues, no change
    }

    cout << total << endl;

    return 0;
}