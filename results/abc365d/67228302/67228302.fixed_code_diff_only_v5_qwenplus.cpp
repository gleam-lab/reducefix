#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'S'}, {'P', 'R'}, {'S', 'P'}}; // Fixed: R beats S, P beats R, S beats P
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    int total = 1;
    char our_last_move = beats[s[0]]; // Our move that beats opponent's first move

    for (int i = 1; i < n; i++) {
        char opponent_move = s[i];
        char our_current_move = beats[opponent_move];

        // If we can use the same move as last time to beat current opponent move
        if (our_last_move == our_current_move) {
            // We don't need to change our move
            continue;
        } else {
            // We need to change our move
            total++;
            our_last_move = our_current_move;
        }
    }

    cout << total << endl;
    return 0;
}