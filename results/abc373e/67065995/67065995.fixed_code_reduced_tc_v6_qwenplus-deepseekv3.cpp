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
    vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = a[ord[i]];
    }
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = b[i] + pref[i];
    }
    vector<ll> ans(n, -1);
    for (int idx = 0; idx < n; ++idx) {
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll current_votes = b[idx] + mid;
            int pos = upper_bound(all(b), current_votes) - b.begin();
            int required_pos = n - m;
            if (pos > required_pos) {
                best = mid;
                high = mid - 1;
                continue;
            }
            ll sum_needed = 0;
            int start = required_pos;
            if (pos <= start) {
                sum_needed = (start - pos) * current_votes - (pref[start] - pref[pos]);
                sum_needed += max(0LL, (n - start) * (current_votes + 1) - (pref[n] - pref[start]));
            } else {
                sum_needed = (n - pos) * (current_votes + 1) - (pref[n] - pref[pos]);
            }
            if (sum_needed <= remaining) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        ans[ord[idx]] = best;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}