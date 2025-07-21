#include<bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10, mod = 1e9 + 7;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<int> a(n + 10);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<ll> prefix_sum(n + 10); // Use ll to prevent overflow
    for(int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }

    map<int, int> count_map;
    ll ans = 0;
    for(int i = 0; i <= n; i++) { // Include prefix_sum[0] = 0
        ll current_mod = (prefix_sum[i] % M + M) % M; // Ensure non-negative
        ans += count_map[current_mod]++;
    }

    cout << ans << "\n";
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