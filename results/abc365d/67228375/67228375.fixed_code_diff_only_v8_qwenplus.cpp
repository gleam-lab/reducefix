#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'S'}, {'P', 'R'}, {'S', 'P'}}; // Fixed: Correct what each move beats
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    // Strategy 1: Start by playing the move that beats the first opponent's move
    int total_1 = 1;
    char my_move = beats[s[0]]; // My first move beats opponent's first move
    for (int i = 1; i < n; i++) {
        char beat_current = beats[s[i]];
        if (beat_current == my_move) {
            // I already have a winning move from previous round, no need to change
            continue;
        } else {
            // Need to change my move to beat current opponent move
            my_move = beat_current;
            total_1++;
        }
    }

    // Strategy 2: Start by playing the same as opponent's first move
    int total_2 = 1;
    my_move = s[0]; // My first move is same as opponent's first move (tie)
    for (int i = 1; i < n; i++) {
        char beat_current = beats[s[i]];
        if (beat_current == my_move) {
            // Current move already beats the opponent's current move
            continue;
        } else {
            // Need to change move
            my_move = beat_current;
            total_2++;
        }
    }

    // Strategy 3: Start by playing the move that loses to opponent's first move
    int total_3 = 1;
    char loses_to_first;
    for (auto& p : beats) {
        if (p.second == s[0]) {
            loses_to_first = p.first;
            break;
        }
    }
    my_move = loses_to_first;
    for (int i = 1; i < n; i++) {
        char beat_current = beats[s[i]];
        if (beat_current == my_move) {
            continue;
        } else {
            my_move = beat_current;
            total_3++;
        }
    }

    cout << max({total_1, total_2, total_3}) << endl;

    return 0;
}