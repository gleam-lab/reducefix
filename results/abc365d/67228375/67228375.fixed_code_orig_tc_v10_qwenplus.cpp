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

    // dp[i][c] = maximum number of wins ending at position i with move c
    vector<map<char, int>> dp(n);
    dp[0]['R'] = 1;
    dp[0]['P'] = 1;
    dp[0]['S'] = 1;

    for (int i = 1; i < n; i++) {
        char opponent = s[i];
        char beat_opponent = beats[opponent];

        // For each possible move at position i
        for (char my_move : {'R', 'P', 'S'}) {
            int best = 0;
            char prev_opponent = s[i-1];
            
            // Transition from previous state
            for (auto &[prev_move, value] : dp[i-1]) {
                // If my current move beats opponent's move, we win this round
                bool win_current = (beats[my_move] == opponent);
                
                // We can transition if the previous state is valid
                // No restriction on move changes - we can change moves freely
                best = max(best, value);
            }
            
            // If our move beats opponent, we get an extra point
            dp[i][my_move] = best + (beats[my_move] == opponent ? 1 : 0);
        }
    }

    // Find maximum value in the last row
    int result = 0;
    for (auto &[move, value] : dp[n-1]) {
        result = max(result, value);
    }
    
    cout << result << endl;

    return 0;
}