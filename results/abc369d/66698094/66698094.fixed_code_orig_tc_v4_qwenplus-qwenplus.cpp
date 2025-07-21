#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

const int MOD = 1e9 + 7, N = 2e5 + 5;

void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (ll &x : v)
        cin >> x;

    ll prev0 = 0, prev1 = 0;
    if (n >= 1) {
        prev0 = v[0];
        prev1 = v[0];
    }

    for (int i = 1; i < n; ++i)
    {
        ll curr0 = max(prev1 + 2 * v[i], prev0);
        ll curr1 = max(prev0 + v[i], prev1);
        prev0 = curr0;
        prev1 = curr1;
    }

    cout << max(prev0, prev1) << '\n';
}

int main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}