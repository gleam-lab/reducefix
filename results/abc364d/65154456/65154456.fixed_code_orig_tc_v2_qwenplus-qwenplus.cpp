#include <bits/stdc++.h>
using namespace std;

// Binary search with prefix sums to find k-th closest point
void solve() {
    int N, Q;
    cin >> N >> Q;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    // Prefix sum array for binary search bounds
    vector<int> queries(Q);
    vector<int> K(Q);
    vector<long long> B(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> B[i] >> K[i];
    }

    for (int q = 0; q < Q; ++q) {
        long long b = B[q];
        int k = K[q];

        // Binary search on distance
        int low = 0;
        int high = 2e8 + 1;

        while (low < high) {
            int mid = (low + high) / 2;

            // Find lower and upper bounds of points within distance `mid` from b
            auto left = lower_bound(A.begin(), A.end(), b - mid);
            auto right = upper_bound(A.begin(), A.end(), b + mid);

            int count = right - left;
            if (count >= k)
                high = mid;
            else
                low = mid + 1;
        }

        cout << low << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}