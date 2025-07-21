#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char getWinningMove(char c) {
    if (c == 'R') return 'P';
    if (c == 'P') return 'S';
    if (c == 'S') return 'R';
    return ' '; // Should not happen
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
    char prev = getWinningMove(s[0]);
    
    for (int i = 1; i < n; ++i) {
        char current = getWinningMove(s[i]);
        if (current != prev) {
            changes++;
            prev = current;
        }
    }
    
    cout << changes + 1 << endl;
    return 0;
}