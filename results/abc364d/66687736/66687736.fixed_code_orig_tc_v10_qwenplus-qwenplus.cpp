#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort A for binary search operations
    sort(A.begin(), A.end());

    for (int q = 0; q < Q; ++q) {
        ll b;
        int k;
        cin >> b >> k;

        // Binary search on the distance
        ll low = 0, high = 200000000; // max possible distance is 2e8
        ll ans = high;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll left = b - mid;
            ll right = b + mid;

            // Find number of elements in [left, right]
            auto l = lower_bound(A.begin(), A.end(), left);
            auto r = upper_bound(A.begin(), A.end(), right);
            int cnt = r - l;

            if (cnt >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}