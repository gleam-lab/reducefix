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
    
    // Try both starting choices: either beat the first gesture or not
    auto calc = [&](char start) {
        char current = start;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (current != win(s[i])) {
                count++;
                current = win(s[i]);
            } else {
                current = s[i];
            }
        }
        return count;
    };
    
    // We can start with any of the three gestures
    int ans = 0;
    ans = max(ans, calc('R'));
    ans = max(ans, calc('P'));
    ans = max(ans, calc('S'));
    
    cout << ans << endl;
    return 0;
}