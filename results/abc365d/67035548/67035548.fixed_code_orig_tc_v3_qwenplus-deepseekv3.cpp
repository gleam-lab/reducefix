#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char getWin(char c) {
    if (c == 'R') return 'P';
    if (c == 'P') return 'S';
    if (c == 'S') return 'R';
    return ' ';
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int maxWins = 0;
    char prev = ' ';
    
    for (int i = 0; i < n; i++) {
        char win = getWin(s[i]);
        if (win != prev) {
            maxWins++;
            prev = win;
        }
    }
    
    // Also consider sequences where we might repeat the winning move
    // when it's the same as the previous move's choice
    prev = ' ';
    int altWins = 0;
    for (int i = n-1; i >= 0; i--) {
        char win = getWin(s[i]);
        if (win != prev) {
            altWins++;
            prev = win;
        }
    }
    
    cout << max(maxWins, altWins) << endl;
    return 0;
}