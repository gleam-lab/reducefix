#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10, mod = 1e9 + 7;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<int> a(n + 10);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<ll> s(n + 10); // Use ll to avoid prefix sum overflow issues
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }

    map<ll, ll> mp; // Use ll for map key to handle large values
    ll ans = 0;
    ll L = s[n];

    // We are looking for pairs (i, j) such that s[j] - s[i-1] ≡ 0 (mod M)
    // => s[j] ≡ s[i-1] (mod M)
    // So we process prefix sums modulo M

    mp[s[0] % M] = 1; // Initialize with s[0] = 0
    for (int i = 1; i <= n; i++) {
        ll curr_mod = s[i] % M;
        ans += mp[curr_mod]; // Count previous indices with same mod value
        mp[curr_mod]++;
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