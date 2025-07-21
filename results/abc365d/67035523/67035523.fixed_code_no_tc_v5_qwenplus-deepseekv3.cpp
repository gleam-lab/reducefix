#include <iostream>
#include <string>
using namespace std;

char getWinningMove(char move) {
    if (move == 'R') return 'P';
    if (move == 'P') return 'S';
    if (move == 'S') return 'R';
    return ' '; // default case (shouldn't happen)
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
    char current = getWinningMove(s[0]);
    changes++;
    
    for (int i = 1; i < n; i++) {
        if (getWinningMove(s[i]) != current) {
            current = getWinningMove(s[i]);
            changes++;
        } else {
            // Need to change to something that doesn't lose to next move
            // We can choose any move except current and its loser
            // The simplest is to choose s[i] itself
            current = s[i];
        }
    }
    
    cout << changes << endl;
    return 0;
}