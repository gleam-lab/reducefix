#include <iostream>
#include <string>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // dummy return
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int ans = 1;
    char current = win(s[0]);
    
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i-1]) {
            char next = win(s[i]);
            if (next != current) {
                ans++;
                current = next;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}