#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    vector<pair<int, int>> queries(Q);

    // Read and prepare the points A and queries
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < Q; i++) {
        cin >> queries[i].first >> queries[i].second;
        queries[i].second--; // Convert k_j to 0-based index
    }
    
    // Sort the array A and the queries
    sort(A.begin(), A.end());
    sort(queries.begin(), queries.end());

    // Binary search function to find the k-th closest point to x
    auto binarySearch = [&](int x, int k) -> int {
        int left = 0, right = N - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A[mid] >= x - k && A[mid] <= x + k) {
                return mid;
            } else if (A[mid] > x + k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1; // Return -1 if no such point exists
    };

    // Process each query and output the result
    for (const auto& q : queries) {
        int B = q.first;
        int k = q.second;
        int index = binarySearch(B, k);
        if (index != -1) {
            cout << abs(B - A[index]) << endl;
        } else {
            cout << -1 << endl; // No such point exists
        }
    }

    return 0;
}