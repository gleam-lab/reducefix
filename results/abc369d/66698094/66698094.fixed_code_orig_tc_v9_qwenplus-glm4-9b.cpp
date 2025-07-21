#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using vi = vector<int>;

#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

const int MOD = 1e9 + 7, N = 2e5 + 5;

void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    ll dp0 = 0, dp1 = 0, prev_dp0 = 0;
    for (ll &x : v)
        cin >> x;
    for (int i = 0; i < n; ++i) {
        prev_dp0 = dp0;
        dp0 = dp1 + 2LL * v[i];
        dp1 = max(dp1, prev_dp0 + v[i]);
    }
    cout << max(dp0, dp1) << '\n';
}

int main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}