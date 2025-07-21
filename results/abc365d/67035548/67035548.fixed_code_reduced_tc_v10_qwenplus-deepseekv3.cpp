#include <iostream>
#include <string>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // default case, though not expected
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
    
    for (int i = 1; i < n; ++i) {
        if (win(s[i]) != current) {
            changes++;
            current = win(s[i]);
        }
    }
    
    cout << changes + 1 << endl;
    return 0;
}