#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int cmp(char x, char y) {
    if (x == 'P') {
        if (y == 'P') return 0;
        if (y == 'R') return -1;
        if (y == 'S') return 1;
    } else if (x == 'R') {
        if (y == 'P') return 1;
        if (y == 'R') return 0;
        if (y == 'S') return -1;
    } else if (x == 'S') {
        if (y == 'P') return -1;
        if (y == 'R') return 1;
        if (y == 'S') return 0;
    }
    return -100; // This case should not happen as 'X' is not a valid character.
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

    int maxChangesFromStart = 0, maxChangesFromEnd = 0;
    int changesFromStart = 0, changesFromEnd = 0;
    char prevFromStart = 'X', prevFromEnd = 'X';

    for (int i = 0; i < n; ++i) {
        if (prevFromStart != win(s[i])) {
            changesFromStart++;
            prevFromStart = win(s[i]);
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        if (prevFromEnd != win(s[i])) {
            changesFromEnd++;
            prevFromEnd = win(s[i]);
        }
    }

    maxChangesFromStart = max(changesFromStart, 0);
    maxChangesFromEnd = max(changesFromEnd, 0);

    cout << max(maxChangesFromStart, maxChangesFromEnd);

    return 0;
}