#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort A for binary search operations
    sort(A.begin(), A.end());
    
    // Precompute prefix sums for distance calculation
    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + A[i];
    }

    for (int q = 0; q < Q; ++q) {
        int b_j, k_j;
        cin >> b_j >> k_j;

        // Binary search to find the k-th smallest distance
        auto distance_kth = [&](int k) {
            // Find position in A where elements are closest to b_j
            int idx = lower_bound(A.begin(), A.end(), b_j) - A.begin();

            // Use two pointers to simulate a heap-like behavior
            int left = idx - 1;
            int right = idx;
            vector<int> k_distances;

            while (k-- && (left >= 0 || right < N)) {
                if (left >= 0 && (right == N || abs(A[left] - b_j) <= abs(A[right] - b_j))) {
                    k_distances.push_back(abs(A[left] - b_j));
                    --left;
                } else {
                    k_distances.push_back(abs(A[right] - b_j));
                    ++right;
                }
            }

            // Return the k-th smallest distance
            return k_distances.back();
        };

        cout << distance_kth(k_j) << "\n";
    }
}

int main() {
    solve();
    return 0;
}