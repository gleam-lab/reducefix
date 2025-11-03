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
    
    // Initialize first move
    dp[0]['R'] = 1;
    dp[0]['P'] = 1;
    dp[0]['S'] = 1;

    for (int i = 1; i < n; i++) {
        char opponent_move = s[i];
        char can_beat = beats[opponent_move]; // our move that beats opponent
        
        // For each possible move we can make at position i
        for (char my_move : {'R', 'P', 'S'}) {
            dp[i][my_move] = 0;
            
            // We get a point if our move beats the opponent's move
            int additional_point = (my_move == can_beat) ? 1 : 0;
            
            // Transition from previous state
            for (char prev_move : {'R', 'P', 'S'}) {
                if (dp[i-1].count(prev_move)) {
                    // We can transition from any previous move
                    dp[i][my_move] = max(dp[i][my_move], dp[i-1][prev_move] + additional_point);
                }
            }
        }
    }

    // Find maximum among all possibilities at the last position
    int result = 0;
    for (auto& [move, val] : dp[n-1]) {
        result = max(result, val);
    }
    
    cout << result << endl;

    return 0;
}