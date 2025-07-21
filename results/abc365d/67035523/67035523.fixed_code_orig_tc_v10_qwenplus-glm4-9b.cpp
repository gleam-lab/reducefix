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
    if (x == 'X') return -100;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    char prev = 'A';
    for (int i = 0; i < n; i++) {
        char current = s[i];
        if (cmp(current, prev) != 0) {
            ans++;
            prev = current;
        }
    }
    cout << ans;
    return 0;
}