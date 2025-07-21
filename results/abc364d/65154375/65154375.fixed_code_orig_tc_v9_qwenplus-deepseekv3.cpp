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

        // Use binary search to find the k-th closest element
        int low = 0, high = N - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            ll val = A[mid];
            ll d = abs(val - b);

            // Count how many elements have distance <= d
            auto left = lower_bound(A.begin(), A.end(), b - d);
            auto right = upper_bound(A.begin(), A.end(), b + d);
            int count = right - left;

            if (count <= k) {
                low = mid + 1;
            } else {
                // Count how many elements have distance < d
                auto left_strict = lower_bound(A.begin(), A.end(), b - (d - 1));
                auto right_strict = upper_bound(A.begin(), A.end(), b + (d - 1));
                int count_strict = right_strict - left_strict;

                if (count_strict > k) {
                    high = mid - 1;
                } else {
                    // Found the correct distance
                    cout << d << '\n';
                    break;
                }
            }
        }
    }

    return 0;
}