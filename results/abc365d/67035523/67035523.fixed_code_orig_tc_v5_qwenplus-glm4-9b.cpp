#include <iostream>
#include <string>

using namespace std;

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
    return -100; // Assume 'X' is not a valid game character
}

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // Return 'X' if x is not a valid game character
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int siz[300009] = {0}; // Initialize all elements to zero
    char prev = 'X'; // Initialize previous character to a non-game character
    int ans = 0; // Initialize transition count

    for (int i = 0; i < n; ++i) {
        if (prev != win(s[i])) { // If there's a transition
            ans++; // Increment transition count
            prev = win(s[i]); // Update previous character
        } else {
            prev = s[i]; // Update previous character if it's a valid game character
        }
    }

    cout << ans;
    return 0;
}