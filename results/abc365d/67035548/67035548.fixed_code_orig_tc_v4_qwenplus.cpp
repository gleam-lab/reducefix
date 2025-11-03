#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int cmp(char x, char y) {
    if (x == 'P') {
        if (y == 'P') return 0;
        if (y == 'R') return 1;
        if (y == 'S') return -1;
    }
    if (x == 'R') {
        if (y == 'P') return -1;
        if (y == 'R') return 0;
        if (y == 'S') return 1;
    }
    if (x == 'S') {
        if (y == 'P') return 1;
        if (y == 'R') return -1;
        if (y == 'S') return 0;
    }
    return -100;
}

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X';
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    // Forward pass: always choose the winning move
    int forward = 0;
    char last_move = 'X'; // no move initially

    for (int i = 0; i < n; i++) {
        char beat = win(s[i]);
        if (last_move != beat) {
            forward++;
            last_move = beat;
        } else {
            last_move = s[i]; // we play the same as opponent to keep state
        }
    }

    // Backward pass: simulate from end to start
    int backward = 0;
    last_move = 'X';

    for (int i = n - 1; i >= 0; i--) {
        char beat = win(s[i]);
        if (last_move != beat) {
            backward++;
            last_move = beat;
        } else {
            last_move = s[i];
        }
    }

    cout << max(forward, backward) << endl;
}