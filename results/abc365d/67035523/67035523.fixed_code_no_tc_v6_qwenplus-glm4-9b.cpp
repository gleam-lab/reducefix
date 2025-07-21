#include <iostream>
#include <string>

using namespace std;

int cmp(char x, char y) {
    if (x == 'P') return (y == 'R') ? 1 : (y == 'S') ? -1 : 0;
    if (x == 'R') return (y == 'P') ? -1 : (y == 'S') ? 1 : 0;
    if (x == 'S') return (y == 'P') ? -1 : (y == 'R') ? 1 : 0;
    if (x == 'X') return -100;
    return 100; // This case should not occur
}

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // This case should not occur
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 1; // Start with 1 because there is at least one valid sequence
    char prev = 'X'; // Initialize with 'X' to avoid unnecessary comparisons

    for (int i = 1; i < n; ++i) {
        if (cmp(s[i], prev) == cmp(win(s[i]), win(prev))) {
            ans++;
            prev = win(s[i]);
        } else {
            prev = s[i];
        }
    }

    cout << ans << endl;
    return 0;
}