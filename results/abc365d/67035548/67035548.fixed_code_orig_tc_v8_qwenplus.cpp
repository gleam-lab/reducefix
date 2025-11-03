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
    int n;
    string s;
    cin >> n >> s;

    // Forward pass: always play the winning move against current opponent
    vector<char> forward_play(n);
    forward_play[0] = win(s[0]);
    for (int i = 1; i < n; i++) {
        if (forward_play[i-1] == win(s[i])) {
            // We can reuse previous winning move
            forward_play[i] = s[i];
        } else {
            forward_play[i] = win(s[i]);
        }
    }
    int forward_changes = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || forward_play[i] != forward_play[i-1]) {
            forward_changes++;
        }
    }

    // Backward pass: process from end to start
    vector<char> backward_play(n);
    backward_play[n-1] = win(s[n-1]);
    for (int i = n-2; i >= 0; i--) {
        if (backward_play[i+1] == win(s[i])) {
            backward_play[i] = s[i];
        } else {
            backward_play[i] = win(s[i]);
        }
    }
    int backward_changes = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || backward_play[i] != backward_play[i-1]) {
            backward_changes++;
        }
    }

    cout << max(forward_changes, backward_changes) << endl;
}