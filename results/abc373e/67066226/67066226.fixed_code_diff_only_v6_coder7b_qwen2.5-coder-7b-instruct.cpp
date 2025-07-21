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

    // Sort indices based on the number of votes in ascending order
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return a[i] < a[j]; });

    // Calculate the prefix sum of sorted votes
    vector<long long> prefix(n + 1);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + a[idx[i]];
    }

    // Initialize answer array with -1
    vector<long long> ans(n, -1);

    // Iterate over each candidate
    for (int i = 0; i < n; ++i) {
        long long target_votes = a[idx[i]] + 1;
        int remaining_candidates = n - i - 1;

        // Binary search to find the minimum additional votes needed
        long long left = 0, right = k + 1;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long total_votes_if_win = prefix[n] - prefix[i + 1] + mid * (remaining_candidates + 1);
            if (total_votes_if_win > prefix[n] - prefix[m]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        // Check if it's possible to win with at least `left` additional votes
        if (left <= k) {
            ans[idx[i]] = left;
        }
    }

    // Output the results
    for (long long x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}