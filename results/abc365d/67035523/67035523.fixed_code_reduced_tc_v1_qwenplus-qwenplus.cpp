#include <iostream>
#include <string>
using namespace std;

// Determine outcome of a single match
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
    return 0; // shouldn't reach here
}

// Return the move that beats given move
char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // invalid
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int ans = 0;
    char last_play = 'X'; // our last move
    
    for (char c : s) {
        if (last_play == 'X' || cmp(win(c), last_play) >= 0) {
            // If we need to change our move
            last_play = win(c);
            ans++;
        }
        // else, continue with same move
    }
    
    cout << ans << endl;
    return 0;
}