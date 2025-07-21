#include <iostream>
#include <string>

using namespace std;

char getWinningMove(char move) {
    if (move == 'R') return 'P';
    if (move == 'S') return 'R';
    if (move == 'P') return 'S';
    return ' '; // default case
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int changes = 0;
    char prev = getWinningMove(s[0]);
    
    for (int i = 1; i < n; i++) {
        char current = getWinningMove(s[i]);
        if (current == prev) {
            // Need to change to avoid consecutive same moves
            changes++;
            // Choose a different winning move that's not the same as previous
            if (s[i] == 'R') prev = 'S';
            else if (s[i] == 'S') prev = 'P';
            else if (s[i] == 'P') prev = 'R';
        } else {
            prev = current;
        }
    }
    
    cout << changes + 1 << endl; // +1 for the first move
    return 0;
}