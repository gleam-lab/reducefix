#include <iostream>
#include <string>

using namespace std;

int cmp(char x, char y) {
    if (x == 'P')
        return y == 'R' ? -1 : (y == 'S' ? 1 : 0);
    if (x == 'R')
        return y == 'S' ? -1 : (y == 'P' ? 1 : 0);
    return y == 'P' ? 1 : (y == 'R' ? -1 : 0);
}

char win(char x) {
    switch (x) {
        case 'R': return 'P';
        case 'S': return 'R';
        case 'P': return 'S';
        default: return 'X';
    }
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int ans = 1;  // There's at least one segment starting with the first character
    char prev = 'X';  // Initialize to a character that won't be in the s string
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'X') continue;
        if (prev == 'X' || cmp(prev, s[i]) > 0) {
            ans++;
            prev = s[i];
        } else {
            prev = win(prev);
        }
    }
    
    cout << ans << endl;
    return 0;
}