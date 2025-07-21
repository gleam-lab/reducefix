#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 4e5 + 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, ans = 0;
    cin >> n >> m;
    
    vector<ll> a(n), prefix_sum(2 * n + 1, 0), count(m, 0);

    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        prefix_sum[i + 1] = (prefix_sum[i] + a[i]) % m;
        count[prefix_sum[i + 1]]++;
    }

    for (ll i = n; i < 2 * n; ++i) {
        prefix_sum[i + 1] = (prefix_sum[i] + a[i - n]) % m;
        ans += count[prefix_sum[i + 1]];
        count[prefix_sum[i + 1]]++;
    }

    cout << ans << '\n';
    return 0;
}