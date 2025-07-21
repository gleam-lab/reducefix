#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
    return 0;
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
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (cmp(s[i], s[(i + 1) % n]) <= 0) {
            ans++;
        }
    }
    
    cout << ans << endl;
    return 0;
}