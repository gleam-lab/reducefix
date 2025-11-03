#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // shouldn't happen
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    // Forward pass: start with first winning move
    int forward = 0;
    char last_move = 'X'; // no move yet

    for (int i = 0; i < n; i++) {
        char needed = win(s[i]);
        if (needed != last_move) {
            forward++;
            last_move = needed;
        }
        // else: reuse same move, no additional stroke
    }

    // Backward pass: simulate from end to beginning
    int backward = 0;
    last_move = 'X';

    for (int i = n - 1; i >= 0; i--) {
        char needed = win(s[i]);
        if (needed != last_move) {
            backward++;
            last_move = needed;
        }
    }

    cout << max(forward, backward) << endl;

    return 0;
}