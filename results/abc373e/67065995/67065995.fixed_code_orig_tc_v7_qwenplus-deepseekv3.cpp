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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    vector<ll> ans(n, 0);
    if (m < n) {
        vector<int> ord(n);
        iota(all(ord), 0);
        sort(all(ord), [&](int i, int j) { return a[i] > a[j]; });
        vector<ll> sorted_a = a;
        sort(all(sorted_a), greater<ll>());
        vector<ll> pref(n + 1);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + sorted_a[i];
        }
        ll remaining = k - sum;
        for (int i = 0; i < n; ++i) {
            ll low = 0, high = remaining + 1;
            ll res = -1;
            while (low <= high) {
                ll mid = (low + high) / 2;
                ll new_vote = a[i] + mid;
                auto it = upper_bound(all(sorted_a), new_vote, greater<ll>());
                int pos = it - sorted_a.begin();
                if (pos < m) {
                    res = mid;
                    high = mid - 1;
                } else {
                    ll needed = 0;
                    if (pos > m) {
                        needed = (pref[pos] - pref[m]) - (pos - m) * (new_vote);
                    }
                    if (needed <= remaining - mid) {
                        res = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
            ans[ord[i]] = res;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}