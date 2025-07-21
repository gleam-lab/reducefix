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
    ll sum_a = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum_a += a[i];
    }
    ll remaining = k - sum_a;
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    auto b = a;
    sort(all(b));
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = b[i] + pref[i];
    }
    vector<ll> ans(n, -1);
    for (int idx = 0; idx < n; idx++) {
        int i = ord[idx];
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = a[i] + mid;
            int pos = upper_bound(all(b), new_votes) - b.begin();
            int needed = n - m;
            if (pos > needed) {
                best = mid;
                high = mid - 1;
                continue;
            }
            ll total = 0;
            if (needed > 0) {
                if (pos <= needed) {
                    total = (needed - pos) * new_votes - (pref[needed] - pref[pos]);
                }
            }
            if (total + mid <= remaining) {
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
    cout << '\n';
    return 0;
}