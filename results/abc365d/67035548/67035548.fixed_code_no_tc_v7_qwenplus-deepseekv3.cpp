#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char getWinningMove(char move) {
    switch(move) {
        case 'R': return 'P';
        case 'P': return 'S';
        case 'S': return 'R';
        default: return move;
    }
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    if (n == 0) {
        cout << 0;
        return 0;
    }
    
    int max_wins = 0;
    char current_move = getWinningMove(s[0]);
    max_wins = 1;
    
    for (int i = 1; i < n; ++i) {
        if (getWinningMove(s[i]) != current_move) {
            max_wins++;
            current_move = getWinningMove(s[i]);
        }
    }
    
    // Check alternative strategy starting with different initial move
    int alt_wins = 0;
    current_move = s[0]; // Don't win first move
    
    for (int i = 1; i < n; ++i) {
        if (getWinningMove(s[i]) != current_move) {
            alt_wins++;
            current_move = getWinningMove(s[i]);
        } else {
            current_move = s[i];
        }
    }
    
    cout << max(max_wins, alt_wins);
    return 0;
}