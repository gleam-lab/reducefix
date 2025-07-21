#include <iostream>
#include <string>

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
    return 'S';
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    char prev = 'X'; // Initialize a non-existent game state

    for (int i = 0; i < n; i++) {
        char next = s[i];
        if (cmp(prev, next) != 0) {
            ans++;
            prev = next;
        }
    }

    cout << ans << endl;
    return 0;
}