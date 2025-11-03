#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    // dp[i][move] = maximum wins up to index i ending with move
    vector<map<char, int>> dp(n);
    
    // Initialize first character
    dp[0]['R'] = ('R' == s[0] ? 1 : 0);
    dp[0]['P'] = ('P' == s[0] ? 1 : 0);
    dp[0]['S'] = ('S' == s[0] ? 1 : 0);

    for (int i = 1; i < n; i++) {
        char opponent = s[i];
        
        // Try each possible move at position i
        for (char my_move : {'R', 'P', 'S'}) {
            int win = (my_move == opponent ? 1 : 0);
            int best_prev = 0;
            
            // Check all possible previous moves
            for (char prev_move : {'R', 'P', 'S'}) {
                // Cannot play the same move consecutively unless it's beneficial
                if (prev_move == my_move) continue;
                
                if (dp[i-1].count(prev_move)) {
                    best_prev = max(best_prev, dp[i-1][prev_move]);
                }
            }
            
            dp[i][my_move] = best_prev + win;
        }
    }

    int result = 0;
    for (auto& p : dp[n-1]) {
        result = max(result, p.second);
    }
    
    cout << result << endl;

    return 0;
}