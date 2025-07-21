#include <iostream>
#include <string>
using namespace std;

int cmp(char x, char y) {
    if (x == 'P' || x == 'R' || x == 'S')
        return (x == 'P' && (y == 'R' || y == 'S')) - (x == 'R' && (y == 'P' || y == 'S')) + (x == 'S' && (y == 'P' || y == 'S'));
    return -100;
}

char win(char x) {
    switch (x) {
        case 'R': return 'P';
        case 'S': return 'R';
        case 'P': return 'S';
        default: return '\0'; // This should never happen as game characters are only R, P, S
    }
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int leftWin = 0, rightWin = 0;
    char prev = 'X'; // Initialize to a non-game character to handle first comparison properly

    // Compare from left to right
    for (int i = 0; i < n; i++) {
        if (cmp(prev, s[i]) < 0) {
            leftWin++;
            prev = win(s[i]);
        } else {
            prev = s[i];
        }
    }

    prev = 'X'; // Reset prev for right to left comparison

    // Compare from right to left
    for (int i = n - 1; i >= 0; i--) {
        if (cmp(prev, s[i]) < 0) {
            rightWin++;
            prev = win(s[i]);
        } else {
            prev = s[i];
        }
    }

    cout << max(leftWin, rightWin) << endl;

    return 0;
}