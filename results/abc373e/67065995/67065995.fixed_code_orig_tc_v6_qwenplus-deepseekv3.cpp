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

    if (m == n) {
        // All candidates will be elected regardless
        for (int i = 0; i < n; i++) {
            cout << 0 << ' ';
        }
        cout << endl;
        return 0;
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
    for (int i = 0; i < n; i++) {
        ll low = 0, high = remaining + 1;
        ll res = high;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_val = a[ord[i]] + mid;
            
            // Find how many are > new_val
            int cnt = b.end() - upper_bound(all(b), new_val);
            if (i >= n - m) cnt--;
            
            if (cnt < m) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (res <= remaining) {
            ans[ord[i]] = res;
        } else {
            ans[ord[i]] = -1;
        }
    }

    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}