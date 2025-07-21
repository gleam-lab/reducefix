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
    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = a[ord[i]];
    }
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = b[i] + pref[i];
    }
    vector<ll> ans(n, -1);
    for (int idx = 0; idx < n; idx++) {
        ll current_votes = b[idx];
        ll low = 0, high = remaining;
        ll best = remaining + 1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current_votes + mid;
            auto it = upper_bound(b.begin(), b.end(), new_votes);
            int count = b.end() - it;
            if (count < m) {
                best = mid;
                high = mid - 1;
            } else {
                ll needed = 0;
                int pos = it - b.begin();
                int start_pos = pos;
                int end_pos = n - m;
                if (start_pos <= end_pos) {
                    needed += pref[end_pos + 1] - pref[start_pos];
                    needed -= new_votes * (end_pos - start_pos + 1);
                    needed += (new_votes + 1) * (end_pos - start_pos + 1);
                    needed -= (pref[end_pos + 1] - pref[start_pos]);
                } else {
                    needed = 0;
                }
                if (needed <= remaining - mid) {
                    best = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        if (best <= remaining) {
            ans[ord[idx]] = best;
        } else {
            ans[ord[idx]] = -1;
        }
    }
    for (auto num : ans) {
        cout << num << ' ';
    }
    return 0;
}