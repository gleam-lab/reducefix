#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<int> dp(n + 1, 0);
    dp[1] = (s[0] == 'S');
    for(int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + (s[i - 1] != s[i - 2]);
    }
    
    cout << dp[n] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}