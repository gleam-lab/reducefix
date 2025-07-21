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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }
    ll remaining = k - total;
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = a[ord[i]];
    }
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = b[i] + pref[i];
    }
    vector<ll> ans(n, -1);
    for (int idx = 0; idx < n; idx++) {
        int i = ord[idx];
        ll low = 0, high = remaining, res = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = a[i] + mid;
            int pos = upper_bound(all(b), new_votes) - b.begin();
            if (pos == n) {
                res = mid;
                high = mid - 1;
                continue;
            }
            int needed_pos = n - m;
            if (idx >= needed_pos) {
                res = mid;
                high = mid - 1;
                continue;
            }
            int cnt = n - pos;
            if (cnt >= m) {
                low = mid + 1;
                continue;
            }
            ll required = new_votes + 1;
            int start = pos;
            int end = n - 1;
            ll sum_needed = 0;
            if (start <= end) {
                sum_needed = (ll)(end - start + 1) * required - (pref[end + 1] - pref[start]);
            }
            if (sum_needed <= remaining - mid) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        ans[i] = res;
    }
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}