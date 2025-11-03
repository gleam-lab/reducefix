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

    // dp[i][move] = maximum rounds won ending with move at position i
    // move: 0 = same as opponent, 1 = beat opponent, 2 = lose to opponent
    vector<vector<int>> dp(n, vector<int>(3, 0));
    
    // Initial state
    dp[0][0] = 0; // play same -> draw
    dp[0][1] = 1; // play what beats opponent -> win
    dp[0][2] = 0; // play what loses to opponent -> loss

    for (int i = 1; i < n; i++) {
        char opp = s[i];
        char beat_opp = beats[opp];
        char lose_to_opp = beats[beat_opp]; // what loses to opp
        
        // Current move is same as opponent (draw)
        dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        
        // Current move beats opponent (win)
        // We can transition from any previous state
        dp[i][1] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) + 1;
        
        // Current move loses to opponent (loss)
        dp[i][2] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
    }

    int result = max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    cout << result << endl;

    return 0;
}