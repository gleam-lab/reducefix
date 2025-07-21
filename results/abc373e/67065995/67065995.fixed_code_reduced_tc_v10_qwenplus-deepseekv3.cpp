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
    for (int i = 0; i < n; ++i) {
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
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = b[i] + pref[i];
    }

    vector<ll> ans(n, -1);
    for (int idx = 0; idx < n; ++idx) {
        int i = ord[idx];
        ll low = 0, high = remaining + a[i];
        ll res = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = a[i] + mid;
            auto it = upper_bound(all(b), new_votes - 1);
            int cnt = b.end() - it;
            if (cnt < m) {
                res = mid;
                high = mid - 1;
            } else {
                ll required = 0;
                int pos = it - b.begin();
                int start = pos;
                int end = n - m;
                if (start <= end) {
                    required = new_votes * (end - start + 1) - (pref[end + 1] - pref[start]);
                }
                if (required <= remaining) {
                    res = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        if (res != -1 && res <= remaining) {
            ans[i] = res;
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