#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char getWinMove(char c) {
    if (c == 'R') return 'P';
    if (c == 'P') return 'S';
    if (c == 'S') return 'R';
    return 'X'; // Should not happen
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    vector<vector<int>> dp(n, vector<int>(3, 0));
    // Index 0: 'R', 1: 'P', 2: 'S'
    char moves[3] = {'R', 'P', 'S'};
    
    for (int i = 0; i < n; ++i) {
        char current = s[i];
        char winMove = getWinMove(current);
        for (int j = 0; j < 3; ++j) {
            if (i == 0) {
                dp[i][j] = (moves[j] == winMove) ? 1 : 0;
            } else {
                int maxPrev = 0;
                for (int k = 0; k < 3; ++k) {
                    if (k == j) {
                        maxPrev = max(maxPrev, dp[i-1][k]);
                    } else {
                        maxPrev = max(maxPrev, dp[i-1][k] + (moves[j] == winMove ? 1 : 0));
                    }
                }
                dp[i][j] = maxPrev;
            }
        }
    }
    
    int maxWins = max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    cout << maxWins << endl;
    
    return 0;
}