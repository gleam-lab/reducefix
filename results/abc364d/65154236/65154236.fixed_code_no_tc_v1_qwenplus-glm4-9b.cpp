#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<long long> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    vector<pair<long long, long long>> queries(Q);
    for (int i = 0; i < Q; ++i) {
        int b, k;
        cin >> b >> k;
        queries[i] = {b, k};
    }

    // Sort queries by b to ensure we only compute distances from A once per b
    sort(queries.begin(), queries.end());

    // Prepare a vector to store distances of A to each b in sorted order
    vector<long long> distances(N + 1);
    for (int i = 1; i <= N; ++i) {
        distances[i] = abs(A[i] - queries[0].first);
    }

    // Process each query
    for (int i = 0; i < Q; ++i) {
        long long b = queries[i].first;
        long long k = queries[i].second;

        // Find the k-th smallest distance
        long long kth_distance;
        {
            long long l = 0, r = N;
            while (l < r) {
                long long mid = l + (r - l) / 2;
                if (distances[mid] < distances[mid + 1]) {
                    if (mid < N && distances[mid] >= distances[mid + 1] - (A[mid + 1] - b)) {
                        r = mid;
                    } else {
                        l = mid + 1;
                    }
                } else {
                    if (mid > 0 && distances[mid] < distances[mid - 1] + (b - A[mid])) {
                        l = mid;
                    } else {
                        r = mid - 1;
                    }
                }
            }
            kth_distance = distances[l];
        }

        // Output the answer for this query
        cout << kth_distance << endl;
    }

    return 0;
}