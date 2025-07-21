#include<bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10, mod = 1e9 + 7;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<ll> a(n + 10);  // Use ll to prevent overflow
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    vector<ll> s(n + 10);  // Prefix sum array
    for(int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }

    map<ll, ll> mp;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ll rem = (s[i] % M + M) % M;  // Normalize to positive remainder

        // Count number of previous prefix sums with same remainder
        ans += mp[rem];

        // Also consider if (prefix_sum[i] - prefix_sum[j]) % M == 0
        // which is equivalent to prefix_sum[i] % M == prefix_sum[j] % M
        mp[rem]++;
    }

    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t = 1;
    while(t--) {
        solve();
    }
    return 0;
}