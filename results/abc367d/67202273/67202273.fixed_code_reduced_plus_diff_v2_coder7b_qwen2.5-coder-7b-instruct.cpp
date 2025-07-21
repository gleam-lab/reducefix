#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 4e5 + 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, m, ans = 0;
    cin >> n >> m;
    
    vector<ll> a(n), prefix_sum(n + 1, 0), count(m);

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        prefix_sum[i + 1] = (prefix_sum[i] + a[i]) % m;
        count[prefix_sum[i + 1]]++;
    }

    for(int i = 0; i <= n; ++i) {
        ans += count[prefix_sum[i]];
        count[prefix_sum[i]]--;
    }

    cout << ans << '\n';

    return 0;
}