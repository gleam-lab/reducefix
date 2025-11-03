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

    // Handle edge case of single character
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    // Strategy 1: Start by playing the move that beats the first opponent move
    int total_1 = 1;
    char last_move = beats[s[0]];
    for (int i = 1; i < n; i++) {
        // If our last move beats current opponent move, we can continue same move
        if (beats[last_move] == s[i]) {
            // We win with same move, so keep it
            continue;
        } else {
            // Need to change move to beat current opponent move
            last_move = beats[s[i]];
            total_1++;
        }
    }

    // Strategy 2: Start by playing the same as opponent's first move
    int total_2 = 1;
    last_move = s[0];
    for (int i = 1; i < n; i++) {
        // If our last move beats current opponent move, we can continue same move
        if (beats[last_move] == s[i]) {
            continue;
        } else {
            // Need to change move to beat current opponent move
            last_move = beats[s[i]];
            total_2++;
        }
    }

    cout << max(total_1, total_2) << endl;

    return 0;
}