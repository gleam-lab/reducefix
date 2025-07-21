#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    vector<map<char, int>> dp(n);
    // Initialize the first step
    for (char c : {'R', 'P', 'S'}) {
        dp[0][c] = (c == beats[s[0]] ? 1 : 0);
    }
    
    for (int i = 1; i < n; ++i) {
        for (char current : {'R', 'P', 'S'}) {
            int max_prev = 0;
            for (char prev : {'R', 'P', 'S'}) {
                if (prev != current) {
                    max_prev = max(max_prev, dp[i-1][prev]);
                }
            }
            dp[i][current] = max_prev + (current == beats[s[i]] ? 1 : 0);
        }
    }
    
    int max_wins = 0;
    for (char c : {'R', 'P', 'S'}) {
        max_wins = max(max_wins, dp[n-1][c]);
    }
    
    cout << max_wins << endl;
    
    return 0;
}