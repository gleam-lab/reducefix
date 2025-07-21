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

    // Case 1: First move is our played move
    int total_1 = 1;
    char last_move = s[0];  // opponent's first move
    char our_move = beats[last_move];  // what we played to beat it
    for (int i = 1; i < n; i++) {
        char opponent_move = s[i];
        if (beats[opponent_move] == our_move) {
            // Same as previous, no change needed
            continue;
        }
        // We need to change our move
        our_move = beats[opponent_move];
        total_1 += 1;
    }

    // Case 2: First round we play the same move as opponent
    int total_2 = 0;
    last_move = s[0];  // we play the same as opponent, so we lose or tie
    for (int i = 1; i < n; i++) {
        char opponent_move = s[i];
        if (beats[opponent_move] == last_move) {
            // Can continue with same move
            continue;
        }
        // Need to switch to beat new opponent move
        last_move = beats[opponent_move];
        total_2 += 1;
    }

    cout << max(total_1, total_2) << endl;

    return 0;
}