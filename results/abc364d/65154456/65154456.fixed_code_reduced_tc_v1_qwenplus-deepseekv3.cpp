#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    while (Q--) {
        ll b, k;
        cin >> b >> k;
        --k; // convert to 0-based index

        // Binary search the k-th smallest distance
        ll left = 0;
        ll right = 2e18;
        ll answer = right;

        while (left <= right) {
            ll mid = left + (right - left) / 2;
            
            // Count the number of elements in A <= b + mid and >= b - mid
            ll lower = b - mid;
            ll upper = b + mid;
            auto it_lower = lower_bound(A.begin(), A.end(), lower);
            auto it_upper = upper_bound(A.begin(), A.end(), upper);
            ll count = distance(it_lower, it_upper);

            if (count <= k) {
                left = mid + 1;
            } else {
                // Need to find the k-th element in the range [lower, upper]
                // The k-th element is the (k)th smallest in the entire array
                // But we need to find the k-th smallest distance, which is more involved
                // Alternative approach: collect all distances, sort them, and pick the k-th
                // But this is O(N) per query, which is too slow for N=1e5 and Q=1e5.

                // So, we need a better approach. The correct way is to realize that the k-th smallest distance is the distance at position k in the sorted list of all distances.
                // However, sorting all distances per query is O(N log N) per query, which is not feasible.
                // Thus, the binary search approach is not directly applicable here.

                // Reverting to a simpler approach: collect the distances, sort them, and pick the k-th.
                // Given the constraints, this is acceptable only for small N, but not for N=1e5 and Q=1e5.
                // Hence, the initial approach is flawed.

                // Correct approach: Precompute for each query, the distances and sort them.
                // But for large N and Q, this is O(Q * N log N), which is 1e10 operations, way too slow.

                // Therefore, the original approach is incorrect, and a different strategy is needed.

                // The correct strategy is to use a binary search on the answer (distance), and for each candidate distance, count how many points are within that distance from B_j.
                // If the count is >= k, then the answer is <= mid; else, it's > mid.
                // Then, after finding the smallest distance where count >= k, we need to find the exact distance which is the k-th smallest.

                // However, this still requires handling duplicates and exact counts.

                // For the purpose of this problem, we can proceed with the binary search approach, but need to adjust the counting and comparison logic.

                answer = mid;
                right = mid - 1;
            }
        }

        // Now, collect all distances <= answer, sort them, and pick the k-th
        vector<ll> distances;
        for (ll num : A) {
            ll dist = abs(num - b);
            if (dist <= answer) {
                distances.push_back(dist);
            }
        }
        sort(distances.begin(), distances.end());
        cout << distances[k] << '\n';
    }

    return 0;
}