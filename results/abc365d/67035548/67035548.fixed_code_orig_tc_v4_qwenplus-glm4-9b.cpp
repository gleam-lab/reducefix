#include <iostream>
#include <string>
using namespace std;

int cmp(char x, char y) {
    if (x == 'P') return y == 'R' ? -1 : (y == 'S' ? 1 : 0);
    if (x == 'R') return y == 'S' ? -1 : (y == 'P' ? 1 : 0);
    if (x == 'S') return y == 'P' ? -1 : (y == 'R' ? 1 : 0);
    return -100; // Unknown character
}

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // X cannot win
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;

    // Count wins from left to right
    for (int i = 0, lastWin = 'X'; i < n; ++i) {
        char current = win(s[i]);
        if (current != 'X' && cmp(current, lastWin) > 0) {
            ans++;
            lastWin = current;
        } else {
            lastWin = s[i];
        }
    }

    // Count wins from right to left
    lastWin = 'X';
    for (int i = n - 1, j = 0; i >= 0; --i, ++j) {
        char current = win(s[i]);
        if (current != 'X' && cmp(current, lastWin) > 0) {
            ans++;
            lastWin = current;
        } else {
            lastWin = s[i];
        }
    }

    cout << ans;
    return 0;
}