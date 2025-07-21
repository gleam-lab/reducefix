#include <iostream>
#include <string>
using namespace std;

char getWinningMove(char move) {
    if (move == 'R') return 'P';
    if (move == 'P') return 'S';
    if (move == 'S') return 'R';
    return ' '; // default case (shouldn't occur)
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
        char optimal = getWinningMove(s[i]);
        if (optimal != current) {
            changes++;
            current = optimal;
        }
    }
    
    cout << changes << endl;
    return 0;
}