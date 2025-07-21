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
    for (int i = 0; i < n; ++i) {
        int pos = i;
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_val = b[pos] + mid;
            int new_pos = upper_bound(all(b), new_val) - b.begin();
            if (new_pos > n - m) {
                best = mid;
                high = mid - 1;
            } else {
                ll needed = (n - m - new_pos + 1) * new_val - (pref[n - m + 1] - pref[new_pos]);
                if (needed <= remaining - mid) {
                    best = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        ans[ord[pos]] = best;
    }
    
    for (int i = 0; i < n; ++i) {
        if (ans[i] != -1) {
            ll required = ans[i];
            if (required == 0) {
                // Check if already secured
                int count = 0;
                for (int j = 0; j < n; ++j) {
                    if (a[j] > a[i]) {
                        count++;
                    }
                }
                if (count < m) {
                    ans[i] = 0;
                } else {
                    ans[i] = -1;
                }
            }
        }
    }
    
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
    
    return 0;
}