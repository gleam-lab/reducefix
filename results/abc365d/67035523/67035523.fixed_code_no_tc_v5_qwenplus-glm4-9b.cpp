#include <iostream>
#include <string>

using namespace std;

int cmp(char x, char y) {
    if (x == 'P') return y == 'P' ? 0 : (y == 'R' ? 1 : -1);
    if (x == 'R') return y == 'P' ? -1 : (y == 'R' ? 0 : 1);
    if (x == 'S') return y == 'P' ? -1 : (y == 'R' ? 1 : 0);
    return -100; // This case should never happen if inputs are valid
}

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // This case should never happen if inputs are valid
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    string response(n, 'X'); // Initialize responses to 'X'
    int changes = 0;
    char prev = 'X';

    for (int i = 0; i < n; i++) {
        char current = s[i];
        char next = (i == n - 1) ? 'X' : s[i + 1]; // Determine the next character, or 'X' if it's the last character
        int order = cmp(current, next);

        if (order == 0) continue; // No change needed if both characters are the same

        if (order < 0) {
            // If current character should win over next, update response and increment changes
            response[i] = win(current);
            changes++;
        } else {
            // If next character should win over current, update response and increment changes
            response[i] = win(next);
            changes++;
        }

        // Update prev to the last character that caused a change
        prev = response[i];
    }

    cout << changes << endl;
    return 0;
}