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

    int total = 1;
    char last_move = beats[s[0]];

    for (int i = 1; i < n; i++) {
        char current_move = beats[s[i]];
        if (current_move == last_move) {
            continue; // Same move as before, no need to change strategy
        }
        // If the current move is different, we need to switch strategy
        total += 1;
        last_move = current_move;
    }

    cout << total << endl;

    return 0;
}