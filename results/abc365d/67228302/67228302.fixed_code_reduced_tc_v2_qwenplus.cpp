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
    char last_winner = beats[s[0]]; // the move that would beat the first opponent's move

    for (int i = 1; i < n; i++) {
        // If current move beats the previous winner, then we don't need a new player
        if (beats[last_winner] == s[i]) {
            // The current move defeats the last winner, so it becomes the new winner
            last_winner = s[i];
        }
        // If the current move is beaten by the last winner, the last winner continues
        else if (beats[s[i]] == last_winner) {
            // last_winner remains unchanged
            continue;
        }
        // If the moves are the same, no change in winner
        else if (s[i] == last_winner) {
            continue;
        }
        // Otherwise, we need a new independent sequence (new player)
        else {
            total++;
            last_winner = beats[s[i]];
        }
    }

    cout << total << endl;

    return 0;
}