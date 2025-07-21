#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

int n, m, k;
int a[N], sorted_votes[N], prefix_sum[N];

// Function to compute the minimum additional votes needed for candidate i
int compute_min_votes(int idx) {
    int low = 0;
    int high = k + 1; // upper bound on extra votes we can give
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        // Total votes of current candidate after adding mid votes
        int curr_total = a[idx] + mid;

        // We need to ensure at least (n - M) candidates have strictly less than curr_total
        // Remaining votes left excluding this candidate's mid votes
        int remaining = k - mid;
        if (remaining < 0) {
            high = mid - 1;
            continue;
        }

        // Binary search to find how many candidates can potentially get >= curr_total
        int l = 0, r = n;
        while (l < r) {
            int mi = (l + r) / 2;
            if (sorted_votes[mi] < curr_total)
                l = mi + 1;
            else
                r = mi;
        }
        int cnt_below = l; // number of candidates with votes < curr_total

        if (cnt_below >= n - m + 1) {
            // Candidate i is in top M, can still win
            result = mid;
            high = mid - 1;
        } else {
            // Not enough candidates below, try more votes
            low = mid + 1;
        }
    }

    return result;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sorted_votes[i] = a[i];
    }
    sort(sorted_votes, sorted_votes + n);

    // Prefix sum for optimization
    prefix_sum[0] = 0;
    for (int i = 1; i <= n; ++i)
        prefix_sum[i] = prefix_sum[i - 1] + sorted_votes[i - 1];

    // Process each candidate
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        res[i] = compute_min_votes(i);
        if (res[i] > k || res[i] < 0)
            res[i] = -1;
    }

    for (int i = 0; i < n; ++i)
        cout << res[i] << " ";
    cout << "\n";

    return 0;
}