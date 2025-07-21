#include <iostream>
#include <string>

using namespace std;

char getWinMove(char opponent) {
    if (opponent == 'R') return 'P';
    if (opponent == 'P') return 'S';
    if (opponent == 'S') return 'R';
    return ' '; // handle unexpected input
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int maxWins = 0;
    char currentMove = getWinMove(s[0]);
    maxWins = 1;
    
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i-1]) {
            // Can continue with the same winning move
            maxWins++;
        } else {
            // Need to switch to the new winning move
            currentMove = getWinMove(s[i]);
            maxWins++;
        }
    }
    
    cout << maxWins << endl;
    return 0;
}