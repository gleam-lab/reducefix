#include <bits/stdc++.h>
using namespace std;

#define ll long long

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

        // Binary search on the answer (distance)
        ll low = 0, high = 2e8 + 10; // since |a_i|, |b_j| <= 1e8
        ll ans = high;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll left = b - mid;
            ll right = b + mid;

            // Find first index >= left
            auto l = lower_bound(A.begin(), A.end(), left);
            // Find first index > right
            auto r = upper_bound(A.begin(), A.end(), right);

            int count = r - l;

            if (count >= k) {
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