#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    // Binary search for the optimal position to remove elements.
    int l = 0, r = N - K - 1;
    int min_diff = INT_MAX;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        int rem = K - (N - 1 - mid);
        int diff = A[mid + 1] - A[rem];

        // Check if this division is valid
        if (mid >= 0 && rem < N && diff < min_diff) {
            min_diff = diff;
            // Try to refine the search for a better solution
            if (mid > 0) r = mid - 1;
            else l = mid + 1;
        } else if (diff >= min_diff) {
            if (mid > 0) r = mid - 1;
            else l = mid + 1;
        } else {
            if (rem + 1 < N) min_diff = A[rem + 1] - A[mid + 1];
            l = mid + 1;
        }
    }

    cout << min_diff << endl;
    return 0;
}