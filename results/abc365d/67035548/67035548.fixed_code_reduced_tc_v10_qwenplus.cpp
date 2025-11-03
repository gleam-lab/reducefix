#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X';
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    // Forward pass: start with first move's winner
    int forward = 0;
    char current = win(s[0]);
    forward++;

    for (int i = 1; i < n; i++) {
        char desired = win(s[i]);
        if (desired != current) {
            forward++;
            current = desired;
        }
    }

    // Backward pass: start from last move's winner
    int backward = 0;
    current = win(s[n-1]);
    backward++;

    for (int i = n-2; i >= 0; i--) {
        char desired = win(s[i]);
        if (desired != current) {
            backward++;
            current = desired;
        }
    }

    cout << max(forward, backward) << endl;
    return 0;
}