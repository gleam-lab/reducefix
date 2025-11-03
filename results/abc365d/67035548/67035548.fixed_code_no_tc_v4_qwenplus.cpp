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
    for (int i = 0; i < n; i++) {
        if (current != win(s[i])) {
            forward++;
            current = win(s[i]);
        }
        current = s[i]; // After playing s[i], the current state becomes s[i]
    }
    
    // Backward pass: start from the end
    int backward = 0;
    current = win(s[n-1]);
    for (int i = n-1; i >= 0; i--) {
        if (current != win(s[i])) {
            backward++;
            current = win(s[i]);
        }
        current = s[i];
    }
    
    cout << max(forward, backward) << endl;
    
    return 0;
}