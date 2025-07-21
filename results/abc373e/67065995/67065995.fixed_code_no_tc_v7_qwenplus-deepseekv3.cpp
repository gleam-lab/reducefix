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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum_a += a[i];
    }
    ll remaining = k - sum_a;
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    vector<ll> b = a;
    sort(all(b));
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = b[i] + pref[i];
    }
    vector<ll> ans(n, -1);
    for (int idx = 0; idx < n; ++idx) {
        int i = ord[idx];
        ll low = 0, high = remaining;
        ll res = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = a[i] + mid;
            auto it = upper_bound(all(b), new_votes);
            int cnt_greater = b.end() - it;
            if (cnt_greater < m) {
                res = mid;
                high = mid - 1;
            } else {
                ll target_pos = n - m;
                ll target_value = b[target_pos];
                if (new_votes >= target_value) {
                    ll sum_needed = 0;
                    ll cnt = 0;
                    for (int j = target_pos; j < n; ++j) {
                        if (b[j] < new_votes) {
                            sum_needed += new_votes - b[j];
                            cnt++;
                        }
                    }
                    if (sum_needed <= remaining) {
                        res = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                } else {
                    low = mid + 1;
                }
            }
        }
        ans[i] = res;
    }
    for (auto num : ans) {
        cout << num << ' ';
    }
    return 0;
}