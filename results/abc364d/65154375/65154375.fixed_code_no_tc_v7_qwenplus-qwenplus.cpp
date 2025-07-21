#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int N, Q;
    cin >> N >> Q;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort the A array to allow binary search and distance calculations
    sort(A.begin(), A.end());

    for (int q = 0; q < Q; ++q) {
        ll b_j;
        int k_j;
        cin >> b_j >> k_j;

        // Binary search to find the k-th smallest distance
        // We will use a sliding window approach on the sorted A array

        // Since we can't directly get the k-th smallest distance efficiently,
        // we will perform a binary search on the possible distance values.
        ll low = 0;
        ll high = 2e8 + 10; // since max |a_i - b_j| <= 2e8

        while (low < high) {
            ll mid = (low + high) / 2;

            // Count how many points in A are within distance <= mid from b_j
            // i.e., count number of A[i] such that |A[i] - b_j| <= mid
            ll left = b_j - mid;
            ll right = b_j + mid;

            int l = lower_bound(A.begin(), A.end(), left) - A.begin();
            int r = upper_bound(A.begin(), A.end(), right) - A.begin();
            int count = r - l;

            if (count >= k_j) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        cout << low << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}