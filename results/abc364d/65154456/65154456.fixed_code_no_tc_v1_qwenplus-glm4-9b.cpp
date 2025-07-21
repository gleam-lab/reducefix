#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    vector<pair<int, int>> queries(Q);
    for (int i = 0; i < Q; ++i) {
        int b, k;
        cin >> b >> k;
        queries[i] = {b, k};
    }

    // Sort the points A to ensure they are in increasing order
    sort(A.begin(), A.end());

    // For each query, find the k-th closest point in A to the point B
    for (int i = 0; i < Q; ++i) {
        int b = queries[i].first;
        int k = queries[i].second;

        // Binary search to find the k-th smallest distance
        int low = 0, high = N - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            long long distance = abs((long long)A[mid] - b);
            if (mid == 0) {
                long long distance2 = abs((long long)A[mid] - b);
                if (distance2 < distance) distance = distance2;
            } else if (mid == N - 1) {
                long long distance2 = abs((long long)A[mid] - b);
                if (distance2 < distance) distance = distance2;
            }

            // If the distance to the middle point is less than or equal to k, search to the right
            if (mid < N - 1 && abs((long long)A[mid + 1] - b) <= distance) {
                low = mid + 1;
            } else {
                // Otherwise, search to the left
                high = mid - 1;
            }
        }

        // Output the k-th smallest distance
        cout << abs((long long)A[low] - b) << endl;
    }

    return 0;
}