#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X';
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int ans = 1; // Start with first move requiring one card
    char current_card = win(s[0]); // Card needed to beat first gesture
    
    for (int i = 1; i < n; i++) {
        char needed_card = win(s[i]);
        if (needed_card != current_card) {
            ans++;
            current_card = needed_card;
        }
    }
    
    cout << ans << endl;
    return 0;
}