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

        // The k-th smallest distance is |A[i] - b| for some i.
        // We need to find the smallest distance such that there are at least k+1 elements with distance <= d.

        // Binary search the answer.
        ll low = 0, high = 2e18;
        ll answer = high;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            
            // Count the number of elements in A where |a - b| <= mid.
            ll left = b - mid;
            ll right = b + mid;
            auto lb = lower_bound(A.begin(), A.end(), left);
            auto ub = upper_bound(A.begin(), A.end(), right);
            int count = ub - lb;
            
            if (count >= k + 1) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << answer << '\n';
    }

    return 0;
}