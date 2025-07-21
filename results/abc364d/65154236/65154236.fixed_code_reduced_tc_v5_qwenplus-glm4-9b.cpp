#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<pair<int, int>> queries(q);

    // Read the positions of points A
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Read the queries which consist of points B and the k-th closest index k_j
    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        queries[i] = {b, k};
    }

    // Sort points A for binary search
    sort(a.begin(), a.end());

    // Sort queries by the position of points B for efficient processing
    sort(queries.begin(), queries.end());

    // Output the result for each query
    for (const auto& [b, k] : queries) {
        // Binary search for the k-th closest A to B
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            if (a[mid] - b < a[mid + 1] - b) {
                high = mid - 1;
            } else {
                low = mid;
            }
        }
        // Calculate and print the distance to the k-th closest A
        cout << abs(a[low] - b) * (k - low) << endl;
    }

    return 0;
}