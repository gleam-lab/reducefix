#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to determine the winner of a RPS move
char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return x; // should never reach here
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    // Calculate maximum wins starting from left
    int max_win = 0;
    char current_move = 'X'; // No move yet

    for (int i = 0; i < n; ++i) {
        if (current_move != win(s[i])) {
            max_win++;
            current_move = win(s[i]);
        } else {
            current_move = s[i];
        }
    }

    // Calculate maximum wins starting from right
    int max_win_rev = 0;
    char current_move_rev = 'X'; // No move yet

    for (int i = n - 1; i >= 0; --i) {
        if (current_move_rev != win(s[i])) {
            max_win_rev++;
            current_move_rev = win(s[i]);
        } else {
            current_move_rev = s[i];
        }
    }

    cout << max(max_win, max_win_rev) << endl;

    return 0;
}