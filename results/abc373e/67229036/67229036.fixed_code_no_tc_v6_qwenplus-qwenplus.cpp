#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

int n, m, k, a[N], sorted_a[N];

// Function to compute the minimum additional votes needed for candidate `i`
int compute_min_votes(int idx) {
    int base = a[idx];
    int left = 0, right = k + 1;

    while (left < right) {
        int mid = (left + right) / 2;
        int total = base + mid;

        // Binary search to find how many candidates have votes > total
        int l = 0, r = n;
        while (l < r) {
            int mval = (l + r) / 2;
            if (sorted_a[mval] > total)
                r = mval;
            else
                l = mval + 1;
        }
        int greater_count = n - l;

        // We need at least (n - M + 1) candidates with <= total votes
        // So at most (M - 1) candidates can have more than total votes
        if (greater_count <= m - 1) {
            // This mid is sufficient
            right = mid;
        } else {
            // Not enough, try higher
            left = mid + 1;
        }
    }

    if (left > k)
        return -1;
    return left;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    // Sort a copy for binary searches
    vector<int> sorted(a, a + n);
    sort(sorted.begin(), sorted.end());

    for (int i = 0; i < n; ++i)
        sorted_a[i] = sorted[i];

    for (int i = 0; i < n; ++i) {
        int res = compute_min_votes(i);
        cout << res << " ";
    }

    return 0;
}