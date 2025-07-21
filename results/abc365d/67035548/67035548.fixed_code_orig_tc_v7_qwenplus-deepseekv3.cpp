#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

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

    int ans = 0;
    char prev = '\0';
    for (int i = 0; i < n; ++i) {
        char current = win(s[i]);
        if (current != prev) {
            ans++;
            prev = current;
        }
    }

    int sub = 0;
    prev = '\0';
    for (int i = n - 1; i >= 0; --i) {
        char current = win(s[i]);
        if (current != prev) {
            sub++;
            prev = current;
        }
    }

    cout << max(ans, sub) << endl;
    return 0;
}