#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

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
        k--; // convert to 0-based index

        // Binary search to find the k-th closest element
        int left = 0, right = N - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            ll d = abs(A[mid] - b);

            // Count the number of elements with distance <= d
            auto lower = lower_bound(A.begin(), A.end(), b - d);
            auto upper = upper_bound(A.begin(), A.end(), b + d);
            int cnt = distance(lower, upper);

            if (cnt > k) {
                // The k-th element is within this distance
                right = mid - 1;
            } else {
                // Need to increase the distance
                left = mid + 1;
            }
        }

        // The k-th closest element is A[left]
        ll res = abs(A[left] - b);
        cout << res << "\n";
    }

    return 0;
}