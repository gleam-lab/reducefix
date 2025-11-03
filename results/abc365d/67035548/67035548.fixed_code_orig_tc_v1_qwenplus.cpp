#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // shouldn't happen
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    // Forward pass: start with no previous winner
    vector<int> forward(n + 1, 0);
    char last = 'X'; // no one has won yet
    
    for (int i = 0; i < n; i++) {
        char winner_needed = win(s[i]);
        if (winner_needed != last) {
            forward[i + 1] = forward[i] + 1;
            last = winner_needed;
        } else {
            forward[i + 1] = forward[i];
            last = s[i]; // current move continues
        }
    }

    // Backward pass: process from end to beginning
    vector<int> backward(n + 1, 0);
    last = 'X';
    
    for (int i = n - 1; i >= 0; i--) {
        char winner_needed = win(s[i]);
        if (winner_needed != last) {
            backward[i] = backward[i + 1] + 1;
            last = winner_needed;
        } else {
            backward[i] = backward[i + 1];
            last = s[i];
        }
    }

    // Find maximum over all splits
    int max_wins = 0;
    for (int i = 0; i <= n; i++) {
        max_wins = max(max_wins, forward[i] + backward[i]);
    }

    cout << max_wins << endl;
    return 0;
}