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

    // DP[i][c] represents the maximum wins up to i-th move if the last move was c
    vector<map<char, int>> dp(n);
    
    // Initialize the first move
    dp[0]['R'] = (beats[s[0]] == 'R') ? 1 : 0;
    dp[0]['P'] = (beats[s[0]] == 'P') ? 1 : 0;
    dp[0]['S'] = (beats[s[0]] == 'S') ? 1 : 0;

    for (int i = 1; i < n; ++i) {
        char current_opponent = s[i];
        char winning_move = beats[current_opponent];
        
        // To compute dp[i][c], we look at all possible previous moves and transitions
        for (char c : {'R', 'P', 'S'}) {
            int max_prev = 0;
            for (char prev_c : {'R', 'P', 'S'}) {
                int wins = dp[i-1][prev_c];
                if (c == winning_move && prev_c != c) {
                    wins += 1;
                }
                max_prev = max(max_prev, wins);
            }
            dp[i][c] = max_prev;
        }
    }

    // The answer is the maximum among the last move's possibilities
    int result = max({dp[n-1]['R'], dp[n-1]['P'], dp[n-1]['S']});
    cout << result << endl;

    return 0;
}