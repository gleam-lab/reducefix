#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        queries[i] = {b, k};
    }

    // Sort points A by their coordinates
    sort(a.begin(), a.end());

    // Precompute cumulative sums of A
    vector<long long> prefix_sum(n);
    prefix_sum[0] = a[0];
    for (int i = 1; i < n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }

    // For each query, find the k-th closest point among A to B_j
    for (auto &q : queries) {
        int b = q.first;
        int k = q.second;
        int low = 0, high = n - 1;
        pair<long long, long long> best_pair(0, -1); // (distance, index)

        // Perform a binary search to find the k-th closest point
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long distances = abs(b - a[mid]);
            if (mid > 0) {
                distances = max(distances, prefix_sum[mid - 1] - prefix_sum[mid]);
            } else {
                distances = max(distances, b);
            }
            if (mid < n - 1) {
                distances = max(distances, prefix_sum[mid + 1] - prefix_sum[mid]);
            } else {
                distances = max(distances, b);
            }

            if (distances < best_pair.first) {
                best_pair = {distances, mid};
            } else if (distances == best_pair.first) {
                best_pair.second = min(best_pair.second, mid);
            }

            if (distances < a[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // Output the distance to the k-th closest point
        cout << best_pair.first << endl;
    }

    return 0;
}