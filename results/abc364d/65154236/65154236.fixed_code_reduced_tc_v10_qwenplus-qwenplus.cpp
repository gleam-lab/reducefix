#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

ll a[MAXN];

// Binary search helper to find the k-th smallest distance
ll query(ll b, int k, int n) {
    // We will use two pointers to maintain a sliding window of size k
    int left = 0, right = 0;
    ll minDist = LLONG_MAX;

    // Sort the A array first
    sort(a, a + n);

    // Sliding window to find the k-th closest
    while (right < n) {
        if (right - left + 1 == k) {
            ll dist = abs(b - a[left]) > abs(b - a[right]) ? abs(b - a[right]) : abs(b - a[left]);
            for (int i = left; i <= right; i++) {
                dist = min(dist, abs(b - a[i]));
            }
            return dist;
        } else if (right - left + 1 < k) {
            right++;
        } else {
            left++;
        }
    }

    // For cases where k == N
    return min(abs(b - a[0]), abs(b - a[n - 1]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    sort(a, a + N);  // Sort once

    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;

        // Binary search bounds
        int lo = 0, hi = N - k;
        // We're looking for the left endpoint of the segment of size k that minimizes the k-th closest
        // This approach doesn't work directly, so we'll compute distances directly instead

        // To get the k-th smallest distance, we can consider a sliding window of size k
        // and find the maximum distance in that window (since we want the k-th smallest)
        // Then take the minimum among all those maxima

        ll res = LLONG_MAX;
        for (int i = 0; i + k <= N; ++i) {
            ll curr_max = 0;
            // Check all points in current window
            for (int j = i; j < i + k; ++j) {
                curr_max = max(curr_max, abs(b - a[j]));
            }
            res = min(res, curr_max);
        }

        cout << res << "\n";
    }

    return 0;
}