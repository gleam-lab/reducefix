#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to determine the winner between two moves
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
    return 0; // Should not reach here
}

// Return the winning move against given move
char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // Invalid input
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    // Calculate maximum wins starting from left
    int left_ans = 0;
    char last_move_left = 'X'; // No previous move initially
    for (int i = 0; i < n; ++i) {
        char best_counter = win(s[i]);
        if (cmp(best_counter, last_move_left) > 0) {
            left_ans++;
            last_move_left = best_counter;
        } else {
            last_move_left = s[i];
        }
    }

    // Calculate maximum wins starting from right
    int right_ans = 0;
    char last_move_right = 'X'; // No previous move initially
    for (int i = n - 1; i >= 0; --i) {
        char best_counter = win(s[i]);
        if (cmp(best_counter, last_move_right) > 0) {
            right_ans++;
            last_move_right = best_counter;
        } else {
            last_move_right = s[i];
        }
    }

    // Output the better of the two strategies
    cout << max(left_ans, right_ans) << endl;

    return 0;
}