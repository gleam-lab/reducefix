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

    // Sort the A array for binary search operations
    sort(A.begin(), A.end());

    for (int q = 0; q < Q; ++q) {
        ll b;
        int k;
        cin >> b >> k;

        // Binary search to find the k-th smallest distance
        // The minimum possible distance is 0, max is 1e8 * 2
        ll low = 0, high = 2e8 + 10;
        ll answer = high;

        while (low <= high) {
            ll mid = (low + high) / 2;

            // Find range of elements in A within distance `mid` from b
            ll left = b - mid;
            ll right = b + mid;

            // Use binary search to count how many elements are in [left, right]
            int l = lower_bound(A.begin(), A.end(), left) - A.begin();
            int r = upper_bound(A.begin(), A.end(), right) - A.begin();
            int count = r - l;

            if (count >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << answer << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}