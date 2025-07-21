#include <iostream>
#include <string>
using namespace std;

int cmp(char x, char y) {
    if (x == 'P' || x == 'R' || x == 'S') {
        if (x == 'P' && y == 'R') return 1;
        if (x == 'R' && y == 'S') return 1;
        if (x == 'S' && y == 'P') return 1;
        if (x == 'P' && y == 'S') return -1;
        if (x == 'R' && y == 'P') return -1;
        if (x == 'S' && y == 'R') return -1;
        return 0;
    }
    return -100;
}

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    return 'S';
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    int count = 0;
    char prev = 'X';

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'X') {
            count = 0; // Reset count when separator is found
        } else if (cmp(s[i], prev) == 1) {
            // Count the winning streaks
            ans++;
            count++;
        } else {
            count = 1; // Reset count for consecutive losses
        }
        prev = s[i];
    }

    cout << count << endl; // Output the length of the longest winning streak
    cout << ans << endl; // Output the total number of winning sequences
    return 0;
}