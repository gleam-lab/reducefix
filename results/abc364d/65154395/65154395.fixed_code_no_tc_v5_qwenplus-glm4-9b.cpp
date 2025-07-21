#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<long long> A(N), B(Q), K(Q);

    // Reading the coordinates of points A
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Reading the coordinates of points B and the corresponding k_j values
    for (int i = 0; i < Q; ++i) {
        cin >> B[i] >> K[i];
    }

    // For each point B, find the k-th closest point in A and calculate the distance
    for (int j = 0; j < Q; ++j) {
        // Binary search to find the k-th closest point
        long long l = 0, r = N - 1, ans = -1;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            // Check if the k-th closest point is in the current range
            if (mid + 1 - B[j] <= K[j] && K[j] <= A[mid] - B[j]) {
                ans = A[mid] - B[j]; // We found our answer, no need to search further to the right
                r = mid - 1;
            } else if (mid + 1 - B[j] > K[j]) {
                r = mid - 1; // The k-th closest point is to the left
            } else {
                l = mid + 1; // The k-th closest point is to the right
            }
        }
        cout << ans << endl;
    }

    return 0;
}