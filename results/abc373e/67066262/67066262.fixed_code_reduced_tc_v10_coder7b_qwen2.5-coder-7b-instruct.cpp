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

    // Sort indices based on the number of votes in descending order
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return a[i] > a[j]; });

    // Calculate the prefix sum array for sorted vote counts
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[idx[i]];
    }

    // Function to determine the minimum additional votes needed for candidate i
    auto min_votes_needed = [&](int i) {
        long long target = a[idx[i]] + 1;
        long long count = 0;
        int j = 0;
        while (j < n && a[idx[j]] >= target) {
            count += a[idx[j]] - target + 1;
            ++j;
        }
        if (count > k) return -1LL;
        long long remaining = k - count;
        long long additional_votes = target * (n - j) - pref[n] + pref[j];
        return additional_votes + remaining;
    };

    // Determine the minimum additional votes needed for each candidate
    vector<long long> result(n, -1);
    for (int i = 0; i < n; ++i) {
        result[idx[i]] = min_votes_needed(i);
    }

    // Output the results
    for (long long v : result) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}