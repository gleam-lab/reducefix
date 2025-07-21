#include <iostream>
#include <string>

using namespace std;

int cmp(char x, char y) {
    if (x == 'P') return -1;
    if (x == 'R') return 1;
    if (x == 'S') return 0;
    if (y == 'P') return 1;
    if (y == 'R') return 0;
    if (y == 'S') return -1;
    return -100; // Assuming 'X' should always be less
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    char prev = 'X'; // Initialize prev to 'X' to handle the first comparison

    for (char c : s) {
        if (cmp(prev, c) != 0) {
            ans++;
            prev = c;
        }
    }

    cout << ans;
    return 0;
}