#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'S'}, {'P', 'R'}, {'S', 'P'}};
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<long long> dp(3, 0); // dp[r], dp[p], dp[s] for counts ending with R, P, S respectively
    dp[s[0] == 'R']++; 
    dp[s[0] == 'P']++;
    dp[s[0] == 'S']++;

    for (int i = 1; i < n; i++) {
        vector<long long> new_dp(3, 0);
        if (s[i] == 'R') {
            new_dp[0] = (dp[1] + dp[2]) % MOD;
        } else if (s[i] == 'P') {
            new_dp[1] = (dp[0] + dp[2]) % MOD;
        } else if (s[i] == 'S') {
            new_dp[2] = (dp[0] + dp[1]) % MOD;
        }
        dp = new_dp;
    }

    long long total = (dp[0] + dp[1] + dp[2]) % MOD;
    cout << total << endl;

    return 0;
}