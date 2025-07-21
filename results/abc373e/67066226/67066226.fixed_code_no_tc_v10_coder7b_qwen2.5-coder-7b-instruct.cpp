#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort indices based on vote count
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return a[i] < a[j]; });

    // Calculate prefix sum of sorted vote counts
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[idx[i]];
    }

    vector<long long> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        int x = a[idx[i]];
        int remaining = k - (pref[n] - pref[i + 1]);

        // If we can't even beat the lowest ranked candidate, we fail
        if (remaining < (n - m - 1)) {
            continue;
        }

        // Binary search for the minimum additional votes needed
        long long lo = 0, hi = remaining;
        while (lo < hi) {
            long long mid = (lo + hi) / 2;
            int rank = upper_bound(a.begin(), a.end(), x + mid) - a.begin();
            if (rank - 1 < n - m) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        // If we can achieve the required rank, update the answer
        if (lo <= remaining) {
            ans[idx[i]] = lo;
        }
    }

    // Output the results
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}