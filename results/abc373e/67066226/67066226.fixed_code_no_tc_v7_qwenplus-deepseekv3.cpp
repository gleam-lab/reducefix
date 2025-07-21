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
    ll total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total += a[i];
    }
    ll remaining = k - total;

    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    auto b = a;
    sort(all(b));
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = b[i] + pref[i];
    }

    vector<ll> ans(n, -1);
    for (int idx = 0; idx < n; ++idx) {
        int i = ord[idx];
        ll current = a[i];
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current + mid;
            int pos = upper_bound(all(b), new_votes) - b.begin();
            int needed_pos = n - m;
            if (pos > needed_pos) {
                best = mid;
                high = mid - 1;
                continue;
            }
            int cnt = n - pos;
            if (cnt < m) {
                best = mid;
                high = mid - 1;
            } else {
                ll required = new_votes * (pos - needed_pos) - (pref[pos] - pref[needed_pos]);
                if (required <= remaining - mid) {
                    best = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        ans[i] = best;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}