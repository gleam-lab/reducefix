#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'S'}, {'P', 'R'}, {'S', 'P'}}; // Fixed: what each move beats
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    // Strategy 1: Start by playing the move that beats the first opponent move
    int total_1 = 1;
    char my_move = beats[s[0]]; // Our move that beats opponent's first move
    for (int i = 1; i < n; i++) {
        // If our previous move loses to current opponent move, we need to change strategy
        if (beats[s[i]] == my_move) {
            // Our current strategy still works, continue with same approach
            my_move = beats[s[i]];
            total_1++;
        } else {
            // We keep the same move as before (no change in our strategy)
            // my_move stays the same
        }
    }

    // Strategy 2: Start by playing the same move as opponent's first move
    int total_2 = 1;
    my_move = s[0];
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == my_move) {
            my_move = beats[s[i]];
            total_2++;
        }
        // Otherwise, keep the same move
    }

    cout << max(total_1, total_2) << endl;

    return 0;
}