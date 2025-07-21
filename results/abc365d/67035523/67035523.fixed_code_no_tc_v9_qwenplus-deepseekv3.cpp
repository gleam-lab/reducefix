#include <iostream>
#include <string>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // default case (should not occur)
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    
    char prev = win(s[0]);
    int ans = 1;
    
    for (int i = 1; i < n; i++) {
        char current = win(s[i]);
        if (current != prev) {
            ans++;
            prev = current;
        } else {
            // Skip the next move to avoid using the same move consecutively
            if (i + 1 < n) {
                prev = win(s[i + 1]);
                i++; // skip the next move
                ans++;
            }
        }
    }
    
    cout << ans;
    return 0;
}