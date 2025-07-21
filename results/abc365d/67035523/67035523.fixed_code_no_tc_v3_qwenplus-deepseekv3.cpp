#include <iostream>
#include <string>
using namespace std;

char getWinningMove(char move) {
    if (move == 'R') return 'P';
    if (move == 'P') return 'S';
    if (move == 'S') return 'R';
    return ' '; // default case
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    if (n == 0) {
        cout << 0;
        return 0;
    }
    
    int changes = 0;
    char current = getWinningMove(s[0]);
    changes++;
    
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            // Need to change to beat both current and next
            current = getWinningMove(s[i]);
            changes++;
        } else {
            // Can use the same optimal move if it beats current
            if (getWinningMove(s[i]) != current) {
                current = getWinningMove(s[i]);
                changes++;
            }
        }
    }
    
    cout << changes;
    return 0;
}