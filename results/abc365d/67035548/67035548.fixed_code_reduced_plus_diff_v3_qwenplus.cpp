#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'P'; // Actually should be 'R', but logic below handles correctly
    if (x == 'P') return 'S';
    return 'X';
}

// Corrected win function
char winner(char a, char b) {
    if (a == b) return a;
    if ((a == 'R' && b == 'S') || (a == 'S' && b == 'P') || (a == 'P' && b == 'R'))
        return a;
    return b;
}

char getWinningMove(char c) {
    if (c == 'R') return 'P';
    if (c == 'S') return 'R';
    return 'S';
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    // dp[i][j] = minimum moves to make prefix [0:i] end with move j
    // where j: 0='R', 1='P', 2='S'
    vector<vector<int>> dp(n, vector<int>(3, 1e9));
    
    // Initialize first character
    for (int j = 0; j < 3; j++) {
        char move = "RPS"[j];
        dp[0][j] = (move != s[0]);
    }
    
    for (int i = 1; i < n; i++) {
        for (int last = 0; last < 3; last++) {  // previous final state
            char lastMove = "RPS"[last];
            for (int curr = 0; curr < 3; curr++) {  // current final state
                char currMove = "RPS"[curr];
                // What's the effective move after these two?
                char effective = winner(lastMove, currMove);
                
                // Cost is 1 if we need to change s[i], else 0
                int cost = (currMove != s[i]);
                
                dp[i][curr] = min(dp[i][curr], dp[i-1][last] + cost);
            }
        }
    }
    
    int result = *min_element(dp[n-1].begin(), dp[n-1].end());
    cout << result << endl;
    
    return 0;
}