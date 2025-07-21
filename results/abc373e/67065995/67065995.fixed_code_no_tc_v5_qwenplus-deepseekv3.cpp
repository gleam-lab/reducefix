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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    vector<ll> sorted_a = a;
    sort(all(sorted_a));
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + sorted_a[i];
    }
    vector<ll> ans(n, -1);
    ll remaining = k - accumulate(all(a), 0LL);
    for (int idx = 0; idx < n; ++idx) {
        int i = ord[idx];
        ll current = a[i];
        ll low = 0, high = remaining;
        ll best_x = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current + mid;
            int pos = upper_bound(all(sorted_a), new_votes) - sorted_a.begin();
            int needed = n - pos;
            if (needed < m) {
                best_x = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (best_x != -1) {
            ans[i] = best_x;
        } else {
            ans[i] = -1;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}