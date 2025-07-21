#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        k--; // convert to 0-based index

        // Binary search the distance d such that exactly k points have distance <= d
        ll left = 0, right = 2e14;
        ll answer = 0;
        while (left <= right) {
            ll mid = (left + right) / 2;
            // Count number of points in A with distance <= mid from b
            auto it_lower = lower_bound(A.begin(), A.end(), b - mid);
            auto it_upper = upper_bound(A.begin(), A.end(), b + mid);
            int count = distance(it_lower, it_upper);
            if (count <= k) {
                left = mid + 1;
            } else {
                // Now, find the smallest d where count > k
                // We need to find the (k+1)th smallest distance
                // So, we need to adjust our approach
                right = mid - 1;
                answer = mid;
            }
        }

        // Now, find the k-th smallest distance
        vector<ll> distances(N);
        for (int i = 0; i < N; ++i) {
            distances[i] = abs(A[i] - b);
        }
        nth_element(distances.begin(), distances.begin() + k, distances.end());
        cout << distances[k] << '\n';
    }

    return 0;
}