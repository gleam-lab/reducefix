#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int N = 200000 + 10;

i64 a[N], b[N], prefix_sum[N];

void solve() {
    i64 n, m, k;
    cin >> n >> m >> k;
    if (m == n) {
        for (int i = 0; i < n; ++i) cout << "0 ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);

    // Compute prefix sums from the end
    prefix_sum[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        prefix_sum[i] = prefix_sum[i + 1] + b[i];
    }

    i64 remaining = k;

    for (int i = 0; i < n; ++i) {
        i64 low = 0, high = remaining, ans = -1;

        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 candidate_score = a[i] + mid;

            // Find how many candidates currently have more votes than the candidate after adding mid votes
            int idx = upper_bound(b, b + n, candidate_score) - b;

            // Number of candidates with strictly greater votes
            int count_greater = n - idx;

            // If already among top M-1, we win
            if (count_greater < m) {
                ans = mid;
                high = mid - 1;
                continue;
            }

            // We need to ensure that even if the remaining votes are distributed to others,
            // our candidate still gets into top M.
            int required = m - 1;
            int need_to_block = count_greater - required;

            // Total votes needed to surpass these `need_to_block` candidates
            i64 total_needed = 0;
            for (int j = idx; j < idx + need_to_block; ++j) {
                total_needed += (candidate_score - b[j] + 1);
            }

            if (mid >= total_needed) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << (ans > remaining ? -1 : ans) << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}