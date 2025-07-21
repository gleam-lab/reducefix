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
        ll low = 0;
        ll high = k;
        ll res = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_val = a[i] + mid;
            auto it = upper_bound(all(b), new_val);
            ll cnt = b.end() - it;
            if (cnt < m) {
                res = mid;
                high = mid - 1;
            } else {
                ll pos = it - b.begin();
                ll needed = 0;
                if (n - pos >= m) {
                    ll start = n - m;
                    needed = (pref[n] - pref[start]) - (new_val + 1) * (n - start) + (new_val + 1 - b[start]) * (n - start);
                    if (start < idx) {
                        needed -= (new_val + 1 - b[idx]);
                    }
                } else {
                    needed = 0;
                }
                if (mid <= k - needed) {
                    res = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        ans[i] = res;
    }
    for (auto num : ans) {
        cout << num << ' ';
    }
    return 0;
}