#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // default case
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int ans1 = 0; // count when starting with winning move
    char prev1 = 'X';
    
    int ans2 = 0; // count when starting with same move
    char prev2 = 'X';
    
    for (int i = 0; i < n; i++) {
        // Strategy 1: alternate between winning and same move
        if (prev1 != win(s[i])) {
            ans1++;
            prev1 = win(s[i]);
        } else {
            prev1 = s[i];
        }
        
        // Strategy 2: alternate between same and winning move
        if (prev2 != s[i]) {
            ans2++;
            prev2 = s[i];
        } else {
            prev2 = win(s[i]);
        }
    }
    
    cout << max(ans1, ans2) << endl;
    return 0;
}