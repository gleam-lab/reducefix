#include<bits/stdc++.h>

using namespace std;
using ll=long long;
typedef pair<int, int>PII;
const int N=2e5+10, mod=1e9+7;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    vector<ll> dp(n + 1);
    dp[0] = 1;  // Base case: 1 way to sum an empty subsequence

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j >= 1; j--) {
            dp[j] = (dp[j] * (1 + dp[j-1])) % mod;  // Update dp to include new subsequences formed by a[i]
            ans = (ans + dp[j] * a[i]) % mod;  // Add the sum of the new subsequences
        }
    }

    cout << ans;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}