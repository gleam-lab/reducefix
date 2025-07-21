#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Function to find the k-th smallest distance from B_j to A array using binary search and prefix sum
void solve() {
    int N, Q;
    cin >> N >> Q;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort A to allow binary search around query points
    sort(A.begin(), A.end());

    for (int q = 0; q < Q; ++q) {
        ll b;
        int k;
        cin >> b >> k;

        // Binary search on distance d
        ll low = 0, high = 2e8; // max possible distance is up to 2*1e8
        while (low < high) {
            ll mid = (low + high) / 2;

            // Find range in A where elements are within [b - mid, b + mid]
            auto l = lower_bound(A.begin(), A.end(), b - mid);
            auto r = upper_bound(A.begin(), A.end(), b + mid);

            int count = r - l;
            if (count >= k)
                high = mid;
            else
                low = mid + 1;
        }

        cout << low << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}