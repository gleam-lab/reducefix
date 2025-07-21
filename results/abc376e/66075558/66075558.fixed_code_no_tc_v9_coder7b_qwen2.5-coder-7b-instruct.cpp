#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long
const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];

    vector<pair<ll, ll>> ab(n);
    for(int i = 0; i < n; ++i) ab[i] = {a[i], b[i]};
    
    sort(ab.begin(), ab.end());

    vector<ll> prefix_sum(n + 1);
    for(int i = 0; i < n; ++i) prefix_sum[i + 1] = prefix_sum[i] + ab[i].second;

    ll res = inf;
    for(int i = 0; i + k - 1 < n; ++i) {
        res = min(res, (prefix_sum[i + k] - prefix_sum[i]) * ab[i + k - 1].first);
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}