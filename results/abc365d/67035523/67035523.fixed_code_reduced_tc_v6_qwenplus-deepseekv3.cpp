#include <iostream>
#include <string>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // Default case (shouldn't happen with valid input)
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int ans = 0;
    char prev = win(s[0]);
    ans++;
    
    for (int i = 1; i < n; i++) {
        if (s[i] != prev) {
            prev = win(s[i]);
            ans++;
        } else {
            prev = s[i];
        }
    }
    
    cout << ans << endl;
    return 0;
}