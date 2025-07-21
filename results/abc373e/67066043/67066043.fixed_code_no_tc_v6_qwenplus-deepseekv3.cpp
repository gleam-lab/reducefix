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
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ll remaining = k - sum;
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
        ll l = 0, r = remaining;
        ll res = -1;
        while (l <= r) {
            ll mid = (l + r) / 2;
            ll new_vote = a[i] + mid;
            auto it = upper_bound(all(b), new_vote);
            int cnt = b.end() - it;
            if (cnt < m) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (res != -1) {
            ll total_used = res;
            auto it = upper_bound(all(b), a[i] + res);
            int cnt = b.end() - it;
            if (cnt >= m) {
                res = -1;
            } else {
                ll needed = 0;
                int pos = it - b.begin();
                int start = n - m;
                if (pos <= start) {
                    needed = 0;
                } else {
                    needed = (pref[n] - pref[pos]) - (a[i] + res) * (n - pos);
                }
                if (total_used + needed <= remaining) {
                    ans[i] = res;
                } else {
                    res = -1;
                }
            }
        }
        if (ans[i] == -1) {
            auto it = upper_bound(all(b), a[i]);
            int cnt = b.end() - it;
            if (cnt < m) {
                ans[i] = 0;
            }
        }
    }
    for (auto num : ans) {
        cout << num << ' ';
    }
    cout << '\n';
    return 0;
}