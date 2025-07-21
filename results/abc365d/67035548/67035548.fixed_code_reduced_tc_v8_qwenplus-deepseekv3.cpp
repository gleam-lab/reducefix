#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    // DP[i][c] represents the maximum wins up to position i with ending move c
    // c can be 'R', 'P', 'S' (0, 1, 2)
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    
    for (int i = 1; i <= n; ++i) {
        char opp = s[i - 1];
        for (int curr = 0; curr < 3; ++curr) {
            char curr_move;
            if (curr == 0) curr_move = 'R';
            else if (curr == 1) curr_move = 'P';
            else curr_move = 'S';
            
            int win = 0;
            if ((curr_move == 'R' && opp == 'S') ||
                (curr_move == 'S' && opp == 'P') ||
                (curr_move == 'P' && opp == 'R')) {
                win = 1;
            }
            
            for (int prev = 0; prev < 3; ++prev) {
                if (i == 1) {
                    dp[i][curr] = max(dp[i][curr], win);
                } else {
                    if (prev != curr) {
                        dp[i][curr] = max(dp[i][curr], dp[i - 1][prev] + win);
                    }
                }
            }
        }
    }
    
    int max_wins = max({dp[n][0], dp[n][1], dp[n][2]});
    cout << max_wins << endl;
    
    return 0;
}