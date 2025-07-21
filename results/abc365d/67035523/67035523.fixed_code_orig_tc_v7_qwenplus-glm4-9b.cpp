#include <iostream>
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
    return -100; // Not a valid character
}

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // Not a valid character
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    char prev = 'A'; // Initialize prev to a non-valid character

    for (int i = 0; i < n; i++) {
        if (prev != win(s[i])) {
            ans++;
            prev = s[i]; // Update prev to the current character
        }
    }

    cout << ans;
    return 0;
}