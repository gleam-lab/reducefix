#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // default case, though not needed if input is correct
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    char prev = 'X';

    // Left to right pass
    for (int i = 0; i < n; ++i) {
        char current = win(s[i]);
        if (current != prev) {
            ++ans;
            prev = current;
        }
    }

    prev = 'X';
    int sub = 0;

    // Right to left pass
    for (int i = n - 1; i >= 0; --i) {
        char current = win(s[i]);
        if (current != prev) {
            ++sub;
            prev = current;
        }
    }

    cout << max(ans, sub) << endl;
    return 0;
}