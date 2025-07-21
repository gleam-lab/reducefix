#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> A(n), B(q);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < q; ++i) cin >> B[i];

    // Sort points A and B
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int j = 0; j < q; ++j) {
        int x = B[j];
        int k;
        cin >> k;

        // Binary search to find the k-th closest point
        auto it = lower_bound(A.begin(), A.end(), x);
        int idx = it - A.begin();

        // Calculate distances to the left and right of the current index
        int left_dist = idx > 0 ? abs(A[idx - 1] - x) : INT_MAX;
        int right_dist = idx < n ? abs(A[idx] - x) : INT_MAX;

        // Find the k-th smallest distance
        if (k == 1) {
            cout << min(left_dist, right_dist) << endl;
        } else {
            k--;
            int dist1 = (idx > 0) ? abs(A[max(0, idx - k)] - x) : INT_MAX;
            int dist2 = (idx < n) ? abs(A[min(n - 1, idx + k)] - x) : INT_MAX;
            cout << min(dist1, dist2) << endl;
        }
    }

    return 0;
}