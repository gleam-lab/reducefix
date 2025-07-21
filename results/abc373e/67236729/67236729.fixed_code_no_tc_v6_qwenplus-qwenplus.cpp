#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int N = 200000 + 10;

void solve() {
    i64 n, m, k;
    cin >> n >> m >> k;
    vector<i64> A(n);
    i64 total = 0;
    for (auto &x : A) {
        cin >> x;
        total += x;
    }
    i64 remaining = k - total;

    if (m == n) {
        // Everyone must be elected. So no need to add anything.
        for (int i = 0; i < n; ++i) cout << 0 << " ";
        cout << "\n";
        return;
    }

    // Create a sorted copy of A to work with
    vector<i64> B = A;
    sort(B.begin(), B.end());

    // Prefix sum from the end
    vector<i64> suffix_sum(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        suffix_sum[i] = suffix_sum[i + 1] + B[i];
    }

    auto is_secure = [&](int idx, i64 added) -> bool {
        i64 score = A[idx] + added;
        // Binary search: number of candidates strictly greater than score
        int pos = upper_bound(B.begin(), B.end(), score) - B.begin();
        int greater_count = n - pos;

        if (greater_count >= m) return false;

        // Need to take top (m - greater_count) candidates among those <= score
        int left = m - greater_count;
        i64 sum_required = suffix_sum[pos - left] - suffix_sum[pos];

        // Adjust if current candidate is among these `left` candidates
        if (A[idx] >= B[pos - left] && A[idx] <= B[pos - 1]) {
            sum_required -= A[idx];
            sum_required += score;
        }

        i64 needed_votes = score * left - sum_required;
        return needed_votes <= remaining;
    };

    for (int i = 0; i < n; ++i) {
        i64 low = 0, high = remaining, ans = -1;
        while (low <= high) {
            i64 mid = (low + high) / 2;
            if (is_secure(i, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << (ans != -1 ? ans : -1) << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}