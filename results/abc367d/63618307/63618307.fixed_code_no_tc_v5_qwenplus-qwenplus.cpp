#include<bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;

const int N = 2e5 + 10, MOD = 1e9 + 7;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = (prefix_sum[i] + a[i]) % MOD;
    }

    map<ll, ll> count_map;
    ll result = 0;

    for (int i = 0; i <= n; ++i) {
        ll rem = prefix_sum[i] % M;
        // Calculate desired remainder to find complementary subarray
        ll target = (rem - ((prefix_sum[n] % M) - rem + M) % M + M) % M;
        result += count_map[target];
        count_map[rem]++;
    }

    cout << result << endl;
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