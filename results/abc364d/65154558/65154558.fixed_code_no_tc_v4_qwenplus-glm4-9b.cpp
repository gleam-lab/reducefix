#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    vector<int> B(Q), K(Q);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < Q; ++i) {
        cin >> B[i] >> K[i];
    }

    // Pair each B with its K and sort by B
    vector<pair<int, int>> queries(Q);
    for (int i = 0; i < Q; ++i) {
        queries[i] = {B[i], K[i]};
    }
    sort(queries.begin(), queries.end());

    // Sort A for binary search
    sort(A.begin(), A.end());

    // Process each query
    for (auto& query : queries) {
        int b = query.first;
        int k = query.second;
        // Binary search to find the k-th closest A index
        int l = 0, r = N;
        while (l < r) {
            int mid = (l + r) / 2;
            if (A[mid] <= b) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        // l is now the smallest index such that A[l] > b
        // We need the (k-1)-th element of distances from A[l-1] to A[l]
        int leftDist = l > 0 ? (b - A[l - 1]) : INT_MAX;
        int rightDist = (l < N) ? (A[l] - b) : INT_MAX;
        vector<int> distances({leftDist, rightDist});
        sort(distances.begin(), distances.end());
        cout << distances[k - 1] << endl;
    }

    return 0;
}