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
    return -100;
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
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int ans = 1; // At least one round is played
    char current_winner = win(s[0]);
    
    for (int i = 1; i < n; i++) {
        if (win(s[i]) == current_winner) {
            // Same winner continues
            continue;
        } else {
            // Winner changes
            ans++;
            current_winner = win(s[i]);
        }
    }
    
    cout << ans << endl;
    return 0;
}