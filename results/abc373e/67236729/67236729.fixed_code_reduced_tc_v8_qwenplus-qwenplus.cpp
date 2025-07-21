#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 2e5 + 10;

void solve() {
    int n, m;
    i64 k;
    cin >> n >> m >> k;

    vector<i64> A(n);
    for (auto &x : A) {
        cin >> x;
    }

    // Total unassigned votes
    i64 total_remaining = k;
    for (auto x : A)
        total_remaining -= x;

    // Sorted list of votes excluding current candidate
    vector<i64> sortedA = A;
    sort(sortedA.begin(), sortedA.end());

    // Prefix sums from the end for quick range sum queries
    vector<i64> suf(n + 2);
    for (int i = n - 1; i >= 0; --i)
        suf[i] = suf[i + 1] + sortedA[i];

    vector<i64> res(n);

    for (int i = 0; i < n; ++i) {
        i64 ai = A[i];
        int ok = total_remaining >= 0 ? 1 : 0;
        if (ok == 0) {
            res[i] = -1;
            continue;
        }

        // Binary search over X (additional votes needed)
        i64 low = 0, high = total_remaining;
        i64 ans = -1;

        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 target = ai + mid;

            // Use binary search to find how many candidates > target
            int l = 0, r = n - 1;
            int idx = n;

            while (l <= r) {
                int m = (l + r) / 2;
                if (sortedA[m] > target)
                    l = m + 1;
                else
                    r = m - 1;
            }
            int count_more = n - l;

            if (count_more < m) {
                ans = mid;
                high = mid - 1;
            } else {
                // Need to try increasing votes
                low = mid + 1;
            }
        }

        res[i] = (ans != -1 ? ans : -1);
    }

    for (auto x : res)
        cout << x << " ";
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    solve();
}