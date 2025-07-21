#include <bits/stdc++.h>
using namespace std;
#define Youssef ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define asc(v) v.begin(), v.end()
#define desc(v) v.rbegin(), v.rend()
#define ll long long
#define mod 1000000007
const int N = 2e5 + 5;
int n;
vector<ll> v;
ll dp[N][2];

void solve() {
    cin >> n;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    // Initialize DP table
    dp[n][0] = dp[n][1] = 0;
    
    // Fill DP table from bottom up
    for (int i = n-1; i >= 0; i--) {
        // If we take the current element with parity 1 (1x)
        ll take1 = dp[i+1][0] + v[i];
        // If we take the current element with parity 0 (2x)
        ll take0 = dp[i+1][1] + 2 * v[i];
        // If we skip the current element
        ll skip = dp[i+1][0];
        
        // Current state depends on previous choices
        dp[i][0] = max(take0, skip);
        dp[i][1] = max(take1, skip);
    }
    
    cout << dp[0][1] << endl;
}

int main() {
    Youssef
    int q = 1;
    // cin >> q;
    while (q--)
        solve();
    return 0;
}