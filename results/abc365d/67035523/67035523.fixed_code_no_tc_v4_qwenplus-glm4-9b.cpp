#include <iostream>
#include <string>

using namespace std;

int cmp(char x, char y) {
    if (x == 'P') return (y == 'P') ? 0 : (y == 'R') ? 1 : -1;
    if (x == 'R') return (y == 'P') ? -1 : (y == 'R') ? 0 : 1;
    if (x == 'S') return (y == 'P') ? -1 : (y == 'R') ? 1 : 0;
    return -100; // This line is not necessary, assuming 'X' is not in the game
}

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return '?'; // This line is not necessary, assuming only 'P', 'R', 'S' are in the game
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    char prev = 'X';
    for (int i = 0; i < n; ++i) {
        if (cmp(s[i], prev) != 0) {
            ans++;
            prev = win(s[i]);
        } else {
            prev = s[i];
        }
    }

    cout << ans << endl;
    return 0;
}