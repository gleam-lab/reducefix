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
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tot += a[i];
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
        ll current = a[ord[i]];
        ll low = 0, high = k + (tot - a[ord[i]]);
        ll best_x = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current + mid;
            int pos = upper_bound(all(b), new_votes) - b.begin();
            int needed = n - m;
            if (pos <= needed) {
                low = mid + 1;
                continue;
            }
            ll sum = pref[n] - pref[pos];
            ll required = new_votes * (n - pos) - sum;
            if (required <= k) {
                best_x = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        ans[ord[i]] = best_x;
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] == -1) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (a[j] > a[i]) cnt++;
            }
            if (cnt < m) ans[i] = 0;
        }
    }
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}