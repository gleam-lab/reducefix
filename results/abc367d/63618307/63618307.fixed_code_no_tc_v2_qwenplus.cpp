#include<bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10, mod = 1e9 + 7;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<ll> s(n + 1);
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i];
    }
    
    map<ll, ll> mp;
    mp[0] = 1; // Empty prefix has sum 0
    ll ans = 0;
    
    for (int i = 1; i <= n; i++) {
        ll remainder = ((s[i] % M) + M) % M; // Normalize to non-negative
        ans += mp[remainder];
        mp[remainder]++;
    }
    
    cout << ans << '\n';
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t = 1;
    while (t--) {
        solve();
    }
    return 0;
}