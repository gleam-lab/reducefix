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
        pref[i + 1] = b[i] + pref[i];
    }

    vector<ll> ans(n, -1);
    for (int idx = 0; idx < n; idx++) {
        int i = ord[idx];
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = a[i] + mid;
            auto it = upper_bound(all(b), new_votes);
            int cnt = b.end() - it;
            if (cnt < m) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (best != -1) {
            ll new_votes = a[i] + best;
            auto it = upper_bound(all(b), new_votes);
            int cnt = b.end() - it;
            ll required = 0;
            if (cnt >= m) {
                best = -1;
            } else {
                int pos = it - b.begin();
                int needed_candidates = max(0, m - 1 - cnt);
                if (needed_candidates > 0) {
                    if (pos - needed_candidates >= 0) {
                        required += new_votes * needed_candidates - (pref[pos] - pref[pos - needed_candidates]);
                    } else {
                        required = LLONG_MAX;
                    }
                }
                if (required <= remaining - best) {
                    ans[i] = best;
                } else {
                    best = -1;
                }
            }
        }
        if (best == -1) {
            auto it = upper_bound(all(b), a[i]);
            int cnt = b.end() - it;
            if (cnt < m) {
                ans[i] = 0;
            }
        }
    }
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}