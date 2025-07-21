#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 2e5 + 10;

void solve() {
    int n, m;
    i64 k;
    cin >> n >> m >> k;
    vector<i64> a(n), sorted_a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sorted_a[i] = a[i];
    }

    sort(sorted_a.begin(), sorted_a.end());

    // Compute prefix sums from the end
    vector<i64> suffix_sum(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        suffix_sum[i] = suffix_sum[i + 1] + sorted_a[i];
    }

    vector<i64> res(n);

    for (int i = 0; i < n; ++i) {
        i64 x = a[i];
        i64 left = 0, right = k + 1;
        while (left < right) {
            i64 mid = (left + right) / 2;
            i64 total = x + mid;

            // Find how many candidates have votes > total
            int idx = upper_bound(sorted_a.begin(), sorted_a.end(), total) - sorted_a.begin();
            int cnt = n - idx;

            if (cnt < m) {
                res[i] = mid;
                right = mid;
            } else {
                // Need to remove top (m - cnt) candidates
                i64 need = 0;
                int rem = m - cnt;
                if (idx - rem >= 0) {
                    need = suffix_sum[idx - rem] - suffix_sum[idx];
                    if (need <= mid) {
                        res[i] = mid;
                        right = mid;
                    } else {
                        left = mid + 1;
                    }
                } else {
                    left = mid + 1;
                }
            }
        }

        if (x + res[i] > sorted_a[n - m]) {
            res[i] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}