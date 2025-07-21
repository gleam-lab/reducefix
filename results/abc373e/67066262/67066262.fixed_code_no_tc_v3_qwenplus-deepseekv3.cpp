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
    vector<ll> sorted_a = a;
    sort(all(sorted_a));

    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = sorted_a[i] + pref[i];
    }

    vector<ll> ans(n, -1);
    for (int idx = 0; idx < n; idx++) {
        ll current = sorted_a[idx];
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current + mid;
            
            auto it = upper_bound(all(sorted_a), new_votes);
            ll count = n - (it - sorted_a.begin());
            
            if (count < m) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (best != -1 && best <= remaining) {
            ans[ord[idx]] = best;
        } else {
            ans[ord[idx]] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] == -1) {
            // Check if already elected
            ll current = a[i];
            auto it = upper_bound(all(sorted_a), current);
            ll count = n - (it - sorted_a.begin());
            if (count < m) {
                ans[i] = 0;
            }
        }
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}