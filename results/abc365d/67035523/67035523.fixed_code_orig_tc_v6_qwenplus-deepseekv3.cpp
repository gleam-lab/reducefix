#include <iostream>
#include <string>

using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // default case, though input should not have 'X'
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    char prev = win(s[0]);
    int ans = 1;
    
    for (int i = 1; i < n; ++i) {
        char current = win(s[i]);
        if (current != prev) {
            ans++;
            prev = current;
        } else {
            // Check if the next character can be won by a different move
            if (i + 1 < n) {
                char next = win(s[i + 1]);
                if (next != current) {
                    prev = next;
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}