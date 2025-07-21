#include <iostream>
#include <string>
using namespace std;

int cmp(char x, char y) {
    if (x == 'P') {
        if (y == 'P') return 0;
        if (y == 'R') return 1;
        return -1;
    }
    if (x == 'R') {
        if (y == 'P') return -1;
        if (y == 'R') return 0;
        return 1;
    }
    if (x == 'S') {
        if (y == 'P') return -1;
        if (y == 'R') return 1;
        return 0;
    }
    return -100;
}

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    return 'S';
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    char prev = 'X'; // Initialize to a non-game character to handle the first element correctly.
    
    for (int i = 0; i < n; ++i) {
        char current = s[i];
        if (prev != win(current)) {
            ans++;
            prev = win(current);
        } else {
            if (cmp(prev, current) == 0) { // Check if it's a tie or if we need to reset the sequence
                prev = 'X'; // Reset prev to a non-game character to start a new sequence
            }
        }
    }

    cout << ans;
    return 0;
}