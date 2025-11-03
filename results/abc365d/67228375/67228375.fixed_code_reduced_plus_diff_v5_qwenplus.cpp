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

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    // dp[i][move] = max wins up to index i ending with move
    vector<map<char, int>> dp(n);
    
    // Initialize first round
    dp[0]['R'] = 1;
    dp[0]['P'] = 1;
    dp[0]['S'] = 1;

    for (int i = 1; i < n; i++) {
        char opp_move = s[i];
        char beat_opp = beats[opp_move]; // our move that beats opponent
        
        // For each possible current move
        for (char my_move : {'R', 'P', 'S'}) {
            int additional = (my_move == beat_opp) ? 1 : 0;
            int best_prev = 0;
            
            // Check all possible previous moves
            for (char prev_move : {'R', 'P', 'S'}) {
                if (dp[i-1].count(prev_move)) {
                    // Can transition if our previous move didn't lose to opponent's previous move
                    char opp_prev = s[i-1];
                    char loses_to = beats[beats[opp_prev]]; // what loses to opponent's move
                    if (prev_move != loses_to) {
                        best_prev = max(best_prev, dp[i-1][prev_move]);
                    }
                }
            }
            
            if (best_prev > 0 || (i == 0)) {
                dp[i][my_move] = best_prev + additional;
            }
        }
    }

    // Find maximum among all possibilities at last position
    int result = 0;
    for (auto& [move, wins] : dp[n-1]) {
        result = max(result, wins);
    }

    cout << result << endl;

    return 0;
}