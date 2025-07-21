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

    // DP[i][last_move] = max wins up to i-th character with last_move
    // last_move can be 'R', 'P', 'S'
    vector<unordered_map<char, int>> dp(n);
    
    // Initialize the first step
    char first_move = s[0];
    for (char move : {'R', 'P', 'S'}) {
        if (move == beats[first_move]) {
            dp[0][move] = 1;
        } else {
            dp[0][move] = 0;
        }
    }

    for (int i = 1; i < n; ++i) {
        char current = s[i];
        for (char current_move : {'R', 'P', 'S'}) {
            int max_prev = 0;
            for (char prev_move : {'R', 'P', 'S'}) {
                if (dp[i-1].count(prev_move)) {
                    int wins = dp[i-1][prev_move];
                    if (prev_move != beats[current]) {
                        // No forced change, can choose any move
                        if (current_move == beats[current]) {
                            wins += 1;
                        }
                    } else {
                        // Forced to change to beat the previous move's counter
                        if (current_move == beats[current]) {
                            wins += 1;
                        }
                    }
                    if (wins > max_prev) {
                        max_prev = wins;
                    }
                }
            }
            dp[i][current_move] = max_prev;
        }
    }

    int max_wins = 0;
    for (auto& entry : dp[n-1]) {
        if (entry.second > max_wins) {
            max_wins = entry.second;
        }
    }

    cout << max_wins << endl;

    return 0;
}