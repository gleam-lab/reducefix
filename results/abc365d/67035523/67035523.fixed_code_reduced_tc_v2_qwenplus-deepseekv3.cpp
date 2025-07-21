#include <iostream>
#include <string>
using namespace std;

char getWinMove(char c) {
    if (c == 'R') return 'P';
    if (c == 'S') return 'R';
    if (c == 'P') return 'S';
    return 'X'; // should not happen
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
    char current = getWinMove(s[0]);
    
    for (int i = 1; i < n; ++i) {
        char next = getWinMove(s[i]);
        if (next != current) {
            changes++;
            current = next;
        }
    }
    
    cout << changes + 1 << endl;
    return 0;
}