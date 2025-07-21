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
    auto b = a;
    sort(all(b));
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + b[i];
    }
    vector<ll> ans(n, -1);
    for (int idx = 0; idx < n; idx++) {
        int i = ord[idx];
        ll low = 0, high = remaining + 1;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = a[i] + mid;
            // Find the first position where b[j] > new_votes - 1
            ll pos = upper_bound(all(b), new_votes - 1) - b.begin();
            ll need = 0;
            // The (n - m) candidates with the highest votes can potentially surpass new_votes
            if (n - pos >= m) {
                // The last (m-1) candidates can be allowed to have more votes than new_votes
                // The remaining (n - m) candidates should not have more.
                need = 0;
                if (n - m > 0) {
                    ll last = n - m;
                    if (last > pos) {
                        need = (new_votes) * (last - pos) - (pref[last] - pref[pos]);
                    }
                }
                if (need <= remaining - mid) {
                    best = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                best = mid;
                high = mid - 1;
            }
        }
        if (best != -1 && best <= remaining) {
            ans[i] = best;
        } else {
            ans[i] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}