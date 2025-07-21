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
    for (int i = 0; i < n; i++) {
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
    for (int i = 0; i < n; i++) {
        pref[i + 1] = b[i] + pref[i];
    }

    vector<ll> ans(n, -1);
    for (int idx = 0; idx < n; idx++) {
        int i = ord[idx];
        ll low = 0, high = remaining;
        ll best_x = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_val = a[i] + mid;
            // Find the first index in b where b[j] > new_val
            ll pos = upper_bound(all(b), new_val) - b.begin();
            // Number of candidates with votes > new_val is n - pos
            if (n - pos < m) {
                best_x = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (best_x != -1 && best_x <= remaining) {
            ans[i] = best_x;
        } else if (n - (upper_bound(all(b), a[i]) - b.begin()) < m) {
            ans[i] = 0;
        }
    }

    for (auto num : ans) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}