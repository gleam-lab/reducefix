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
    
    // Forward pass: try to maximize wins by choosing optimal sequence
    vector<int> forward(n + 1, 0);
    char last = 'X'; // no previous action
    
    for (int i = 0; i < n; i++) {
        char beat = win(s[i]);
        if (last != beat) {
            forward[i+1] = forward[i] + 1;
            last = beat;
        } else {
            forward[i+1] = forward[i];
            last = s[i]; // we play what opponent played (no win)
        }
    }
    
    // Backward pass: start from end and go backwards
    vector<int> backward(n + 1, 0);
    last = 'X';
    
    for (int i = n - 1; i >= 0; i--) {
        char beat = win(s[i]);
        if (last != beat) {
            backward[i] = backward[i+1] + 1;
            last = beat;
        } else {
            backward[i] = backward[i+1];
            last = s[i];
        }
    }
    
    // Find maximum over all splits
    int max_wins = 0;
    for (int i = 0; i <= n; i++) {
        max_wins = max(max_wins, forward[i] + backward[i]);
    }
    
    cout << max_wins << endl;
}