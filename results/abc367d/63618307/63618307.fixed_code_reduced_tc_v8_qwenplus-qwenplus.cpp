#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10, mod = 1e9 + 7;

void solve()
{
    int n;
    ll M;
    cin >> n >> M;
    vector<ll> a(n + 10);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> s(n + 1);
    for (int i = 0; i < n; i++) {
        s[i + 1] = (s[i] + a[i]) % M;
    }

    map<ll, ll> mp;
    ll ans = 0;
    mp[s[0]]++;
    for (int i = 1; i <= n; i++) {
        // Count number of previous prefix sums with same value modulo M
        ans += mp[s[i] % M]++;
    }

    cout << ans << "\n";
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