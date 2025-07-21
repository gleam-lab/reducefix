#include <iostream>
#include <string>

using namespace std;

int cmp(char x, char y) {
    if (x == 'P' || x == 'R' || x == 'S') {
        if (x == 'P' && (y == 'R' || y == 'S')) return 1;
        if (x == 'R' && (y == 'S' || y == 'P')) return 1;
        if (x == 'S' && (y == 'P' || y == 'R')) return 1;
        return -1;
    }
    return -100;
}

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // This line is technically unnecessary since 'X' is not a valid input to win function
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int ans = 0;
    char prev = 'X'; // Initialize prev to a non-playing character to handle the first transition

    for (int i = 0; i < n; i++) {
        if (cmp(prev, s[i]) != 1) { // If the previous character does not win against the current character
            ans++;
            prev = s[i]; // Update prev to the current character
        }
    }

    cout << ans;
    return 0;
}