#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<pair<int, int>> queries(q);
    
    // Reading points A
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Reading queries
    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        queries[i] = {b, k};
    }
    
    // Sorting queries by the point B to optimize the distance calculations
    sort(queries.begin(), queries.end());
    
    // Precomputing the frequency of points A to speed up range queries
    vector<int> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + 1;
    }
    
    // For each query, find the k-th closest point A to point B
    for (const auto& [b, k] : queries) {
        int left = 0, right = n - 1;
        // Binary search to find the k-th closest point
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            // Find the first point in A that is at least k distance apart
            int needed = k;
            while (mid > 0 && needed == prefixSum[mid]) {
                needed -= prefixSum[mid];
                mid--;
            }
            // Check if the current mid is a valid k-th closest
            if (mid >= 0 && needed <= prefixSum[mid - 1]) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        // Output the distance between the k-th closest point and B
        cout << abs(a[left] - b) << endl;
    }
    
    return 0;
}