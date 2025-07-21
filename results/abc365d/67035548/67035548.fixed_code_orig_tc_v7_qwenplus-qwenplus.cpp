#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Determine the result of a single move against another
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
    return -100; // Placeholder logic, not used in solution
}

// Return the winning move for a given character
char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // Not used
}

int solve(const string& s) {
    int n = s.size();
    int ans = 0;
    char last_move = 'X'; // No move yet

    for (int i = 0; i < n; ++i) {
        char best_response = win(s[i]);
        if (best_response != last_move) {
            ans++;
            last_move = best_response;
        } else {
            last_move = s[i]; // We must play this to avoid repeating the same move
        }
    }

    return ans;
}

int solve_reverse(const string& s) {
    int n = s.size();
    int ans = 0;
    char last_move = 'X'; // No move yet

    for (int i = n-1; i >= 0; --i) {
        char best_response = win(s[i]);
        if (best_response != last_move) {
            ans++;
            last_move = best_response;
        } else {
            last_move = s[i]; // We must play this to avoid repeating the same move
        }
    }

    return ans;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    int forward = solve(s);
    int backward = solve_reverse(s);
    cout << max(forward, backward) << endl;
    return 0;
}