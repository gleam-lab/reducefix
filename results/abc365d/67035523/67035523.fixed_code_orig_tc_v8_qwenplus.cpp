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
    
    int ans = 1; // First move always counts
    char current = win(s[0]); // What we need to play to beat first opponent move
    
    for (int i = 1; i < n; i++) {
        char needed = win(s[i]);
        if (needed != current) {
            ans++;
            current = needed;
        }
    }
    
    cout << ans << endl;
    return 0;
}