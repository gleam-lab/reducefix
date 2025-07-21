#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (m == n) {
        for (int i = 0; i < n; i++) {
            cout << 0 << ' ';
        }
        return 0;
    }

    vector<ll> ans(n, -1);
    vector<ll> sorted_a = a;
    sort(all(sorted_a));
    
    for (int i = 0; i < n; i++) {
        ll low = 0, high = k;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total = a[i] + mid;
            auto it = upper_bound(all(sorted_a), total);
            int cnt = sorted_a.end() - it;
            if (a[i] + mid > 0) {
                if (sorted_a.back() == total) {
                    cnt++;
                }
            }
            if (cnt < m) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        ans[i] = best;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}