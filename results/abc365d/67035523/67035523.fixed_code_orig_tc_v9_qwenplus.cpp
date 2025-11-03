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
    
    vector<int> dp(n + 1, 0);
    char prev_win = 'X'; // No previous winning move
    
    for (int i = 0; i < n; i++) {
        char current_win = win(s[i]);
        
        if (current_win != prev_win) {
            dp[i + 1] = dp[i] + 1;
            prev_win = current_win;
        } else {
            dp[i + 1] = dp[i];
            // prev_win remains same
        }
    }
    
    cout << dp[n] << endl;
    return 0;
}