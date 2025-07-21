#include <iostream>
#include <string>
using namespace std;

// Function to determine the outcome of a move against its counter
char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return x; // Just in case
}

int max_anti_cyclic_moves(const string& s) {
    int n = s.size();
    
    // First pass: greedy from left to right
    int count1 = 0;
    char last_move = 'X'; // No move initially
    for (int i = 0; i < n; ++i) {
        char best_move = win(s[i]);
        if (best_move != last_move) {
            ++count1;
            last_move = best_move;
        } else {
            last_move = s[i]; // Same as opponent's move if we can't change
        }
    }

    // Second pass: greedy from right to left
    int count2 = 0;
    last_move = 'X'; // Reset
    for (int i = n - 1; i >= 0; --i) {
        char best_move = win(s[i]);
        if (best_move != last_move) {
            ++count2;
            last_move = best_move;
        } else {
            last_move = s[i];
        }
    }

    return max(count1, count2);
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << max_anti_cyclic_moves(s) << endl;
    return 0;
}