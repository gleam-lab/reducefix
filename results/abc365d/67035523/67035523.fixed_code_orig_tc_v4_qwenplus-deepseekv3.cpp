#include <iostream>
#include <string>

using namespace std;

char getWinMove(char opponent) {
    if (opponent == 'R') return 'P';
    if (opponent == 'P') return 'S';
    if (opponent == 'S') return 'R';
    return ' '; // Handle unexpected characters if any
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
    char prevMove = ' '; // Initialize to an invalid move
    
    for (int i = 0; i < n; ++i) {
        char currentWinMove = getWinMove(s[i]);
        if (currentWinMove != prevMove) {
            ++changes;
            prevMove = currentWinMove;
        }
    }
    
    cout << changes << endl;
    return 0;
}