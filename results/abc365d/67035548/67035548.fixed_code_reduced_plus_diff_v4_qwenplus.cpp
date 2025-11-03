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

    // Forward pass: start with first move
    vector<int> forward(n + 1, 0);
    char current = win(s[0]);
    forward[0] = 1;
    
    for (int i = 1; i < n; i++) {
        char wanted = win(s[i]);
        if (wanted == current) {
            // Same as previous, no change
            forward[i] = forward[i-1];
        } else {
            // Need to switch
            forward[i] = forward[i-1] + 1;
            current = wanted;
        }
    }
    forward[n] = forward[n-1];

    // Backward pass: start from end and go backwards
    vector<int> backward(n + 1, 0);
    current = win(s[n-1]);
    backward[n-1] = 1;
    
    for (int i = n-2; i >= 0; i--) {
        char wanted = win(s[i]);
        if (wanted == current) {
            backward[i] = backward[i+1];
        } else {
            backward[i] = backward[i+1] + 1;
            current = wanted;
        }
    }
    backward[n] = 0;

    // Try all possible split points
    int max_wins = 1;
    for (int i = 0; i <= n; i++) {
        int total = 0;
        if (i > 0) total += forward[i-1];
        if (i < n) total += backward[i];
        max_wins = max(max_wins, total);
    }

    cout << max_wins << endl;
}