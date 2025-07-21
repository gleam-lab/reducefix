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

    if (m == n) {
        for (int i = 0; i < n; i++) {
            cout << "0 ";
        }
        cout << endl;
        return 0;
    }

    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] > a[j]; });
    vector<ll> sorted_a(n);
    for (int i = 0; i < n; i++) {
        sorted_a[i] = a[ord[i]];
    }
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + sorted_a[i];
    }

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; i++) {
        int original_pos = ord[i];
        ll current_votes = sorted_a[i];
        ll low = 0;
        ll high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current_votes + mid;
            int pos = upper_bound(all(sorted_a), new_votes, greater<ll>()) - sorted_a.begin();
            if (i < pos) pos--;
            if (pos < m) {
                best = mid;
                high = mid - 1;
            } else {
                ll needed = 0;
                if (m > 0) {
                    needed = max(0LL, new_votes * m - pref[m]);
                    if (i < m) {
                        needed -= new_votes - current_votes;
                    }
                }
                if (needed <= remaining) {
                    best = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        ans[original_pos] = best;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}