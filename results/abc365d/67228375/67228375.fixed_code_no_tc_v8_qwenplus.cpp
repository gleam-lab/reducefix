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

    // Strategy 1: Start by playing what beats the first opponent move
    int total_1 = 1;
    char my_move = beats[s[0]]; // My first move beats opponent's first move
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == my_move) {
            // My current move beats opponent's next move, so I can reuse it
            continue;
        } else {
            // I need to change my move to beat opponent's next move
            my_move = beats[s[i]];
            total_1 += 1;
        }
    }

    // Strategy 2: Start by playing the same as first opponent move
    int total_2 = 1;
    my_move = s[0]; // My first move is same as opponent's first move
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == my_move) {
            // My current move beats opponent's next move, so I can reuse it
            continue;
        } else {
            // I need to change my move to beat opponent's next move
            my_move = beats[s[i]];
            total_2 += 1;
        }
    }

    cout << max(total_1, total_2) << endl;

    return 0;
}