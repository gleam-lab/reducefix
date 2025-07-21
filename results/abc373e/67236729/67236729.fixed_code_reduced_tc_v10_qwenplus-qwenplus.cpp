#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
    i64 n, m, k;
    cin >> n >> m >> k;
    
    vector<i64> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    
    i64 remaining = k;
    for (auto x : a) {
        remaining -= x;
    }
    
    if (m >= n) {
        // If we need less than M candidates to be better for us to win, and there are not enough candidates,
        // then everyone can win
        for (int i = 0; i < n; ++i) {
            cout << 0 << " ";
        }
        cout << "\n";
        return;
    }

    // Sort the array to help determine how many candidates could have more votes
    vector<i64> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());

    // Compute prefix sums from the end for efficient range sum queries
    vector<i64> suffix_sum(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        suffix_sum[i] = suffix_sum[i + 1] + sorted_a[i];
    }

    auto needed_votes = [&](i64 candidate_votes, i64 extra) {
        // Binary search for how many candidates have strictly more votes
        int low = 0, high = n;
        while (low < high) {
            int mid = (low + high) / 2;
            if (sorted_a[mid] < candidate_votes + extra) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        int num_better = n - low;

        if (num_better >= m) {
            return false;  // Too many better candidates even with extra
        }

        // We need to ensure at least (m - num_better) candidates have <= our candidate
        int idx = n - (m - num_better);
        if (idx <= low) {
            return true;  // Already good
        }

        // Compute how much it would cost to bring those candidates down
        i64 total_available = remaining - extra;
        i64 threshold = candidate_votes + extra;
        i64 required = suffix_sum[low] - suffix_sum[idx] - (i64)(idx - low) * threshold;

        return required <= total_available;
    };

    vector<i64> result(n);
    for (int i = 0; i < n; ++i) {
        i64 lo = 0, hi = remaining + 1;
        while (lo < hi) {
            i64 mid = (lo + hi) / 2;
            if (needed_votes(a[i], mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        if (lo > remaining) {
            result[i] = -1;
        } else {
            result[i] = lo;
        }
    }

    for (auto x : result) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}