#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    vector<pair<long long, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        long long b;
        int k;
        cin >> b >> k;
        queries[i] = {b, k};
    }

    // Sort the queries by the point b to optimize the binary search
    sort(queries.begin(), queries.end());

    // Sort the points A to find the k-th closest efficiently
    sort(A.begin(), A.end());

    // We need to answer k-th closest queries in sorted order of b
    for (const auto& [b, k] : queries) {
        // Binary search to find the k-th closest point
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            // Count how many points from A are closer to b than A[mid]
            int count = 0;
            for (int i = 0; i <= mid; ++i) {
                if (A[i] < b) {
                    count++;
                }
            }
            if (count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        // Calculate the distance to the k-th closest point
        long long distance = abs(A[left] - b);
        cout << distance << endl;
    }

    return 0;
}