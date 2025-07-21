#include <iostream>
#include <string>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // fallback
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int changes = 0;
    char current = win(s[0]);
    changes++;
    
    for (int i = 1; i < n; i++) {
        if (s[i] == current) {
            continue;
        }
        char next = win(s[i]);
        if (next != current) {
            changes++;
            current = next;
        }
    }
    
    cout << changes << endl;
    return 0;
}