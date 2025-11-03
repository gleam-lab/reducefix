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
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    // Forward pass: start with first character's winner
    int forward = 1;
    char current = win(s[0]);
    
    for (int i = 1; i < n; i++) {
        if (current != win(s[i])) {
            forward++;
            current = win(s[i]);
        } else {
            current = s[i]; // continue the same sequence
        }
    }
    
    // Backward pass: start from the end
    int backward = 1;
    current = win(s[n-1]);
    
    for (int i = n-2; i >= 0; i--) {
        if (current != win(s[i])) {
            backward++;
            current = win(s[i]);
        } else {
            current = s[i];
        }
    }
    
    cout << max(forward, backward) << endl;
    return 0;
}