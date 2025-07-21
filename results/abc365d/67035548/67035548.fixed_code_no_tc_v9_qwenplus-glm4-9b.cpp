#include <iostream> // cout, endl, cin
#include <string> // string
using namespace std;

int cmp(char x, char y) {
    if (x == 'P') {
        if (y == 'P') return 0;
        if (y == 'R') return -1;
        if (y == 'S') return 1;
    }
    if (x == 'R') {
        if (y == 'P') return 1;
        if (y == 'R') return 0;
        if (y == 'S') return -1;
    }
    if (x == 'S') {
        if (y == 'P') return -1;
        if (y == 'R') return 1;
        if (y == 'S') return 0;
    }
    return -100; // Assuming 'X' is not a valid comparison character
}

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // Assuming 'X' is not a winning character
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;

    // Calculate the maximum number of consecutive winning moves from the start
    for (int i = 1; i < n; i++) {
        if (s[i] != 'X' && s[i-1] == win(s[i])) {
            ans++;
        } else {
            ans = 1;
        }
    }

    // Calculate the maximum number of consecutive winning moves from the end
    int sub = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] != 'X' && s[i+1] == win(s[i])) {
            sub++;
        } else {
            sub = 1;
        }
    }

    // Output the maximum of the two counts
    cout << max(ans, sub);

    return 0;
}