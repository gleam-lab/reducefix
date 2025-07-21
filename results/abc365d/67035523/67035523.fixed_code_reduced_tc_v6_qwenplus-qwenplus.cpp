#include <iostream>
#include <string>
using namespace std;

// Function to determine the winner of a single RPS game
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

// Return the move that beats the given move
char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // shouldn't reach here
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    char last_move = 'X'; // No move yet

    for (char c : s) {
        // If our previous move beats current opponent move, do nothing
        // Else we need to make a new move that beats the current opponent move
        if (cmp(last_move, c) != 1) {
            ans++;
            last_move = win(c);
        }
    }

    cout << ans << endl;
    return 0;
}