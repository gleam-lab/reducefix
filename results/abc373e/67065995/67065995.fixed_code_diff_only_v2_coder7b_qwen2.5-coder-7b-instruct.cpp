#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool can_win(ll x, vector<ll>& a, int n, int m, ll k) {
    vector<ll> b(a);
    for (int i = 0; i < n; ++i) b[i] += x;
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    ll total_votes = accumulate(b.begin(), b.begin() + n - m, 0LL);
    return total_votes > k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        if (a[i] * 2 > k) continue;
        ll lo = 0, hi = k - a[i];
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            if (can_win(mid, a, n, m, k)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        if (lo != k - a[i]) ans[i] = lo;
    }

    for (auto i : ans) cout << i << " ";

    return 0;
}