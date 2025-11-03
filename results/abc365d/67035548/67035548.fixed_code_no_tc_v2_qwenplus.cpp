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
    
    // Forward pass: start with first character's winner
    int ans1 = 0;
    char current = win(s[0]);
    for (int i = 0; i < n; i++) {
        if (current != win(s[i])) {
            ans1++;
            current = win(s[i]);
        }
        current = s[i]; // After playing, the played move becomes current
    }
    
    // Backward pass: start from end
    int ans2 = 0;
    current = win(s[n-1]);
    for (int i = n-1; i >= 0; i--) {
        if (current != win(s[i])) {
            ans2++;
            current = win(s[i]);
        }
        current = s[i];
    }
    
    cout << max(ans1, ans2) << endl;
    
    return 0;
}