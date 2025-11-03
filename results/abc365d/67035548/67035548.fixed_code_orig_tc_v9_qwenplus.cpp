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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    // Forward pass: try to maximize wins by choosing optimal sequence
    vector<int> forward(n + 1, 0);
    char last = 'X'; // no move initially
    
    for (int i = 0; i < n; i++) {
        char best = win(s[i]);
        if (best != last) {
            forward[i+1] = forward[i] + 1;
            last = best;
        } else {
            forward[i+1] = forward[i];
            last = s[i]; // play what's needed
        }
    }

    // Backward pass: start from end and go backward
    vector<int> backward(n + 1, 0);
    last = 'X';
    
    for (int i = n - 1; i >= 0; i--) {
        char best = win(s[i]);
        if (best != last) {
            backward[i] = backward[i+1] + 1;
            last = best;
        } else {
            backward[i] = backward[i+1];
            last = s[i];
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, forward[i] + backward[i]);
    }

    cout << ans << endl;
    
    return 0;
}