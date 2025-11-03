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
    
    int ans = 0;
    char current = 'X'; // No active move at the beginning
    
    for (int i = 0; i < n; i++) {
        char desired = win(s[i]);
        
        if (current != desired) {
            ans++;
            current = desired;
        }
        // If same as current, we continue using the same hand (no change needed)
    }
    
    cout << ans << endl;
    return 0;
}