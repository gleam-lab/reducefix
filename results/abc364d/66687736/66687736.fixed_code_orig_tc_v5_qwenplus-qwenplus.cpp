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
        ll B;
        int K;
        cin >> B >> K;

        // Binary search for the k-th smallest distance
        ll low = 0, high = 1e9 + 7; // max possible distance is 2*1e8
        while (low < high) {
            ll mid = (low + high) / 2;

            // Find the range [L, R] in A where A[i] is within [B - mid, B + mid]
            int L = lower_bound(A.begin(), A.end(), B - mid) - A.begin();
            int R = upper_bound(A.begin(), A.end(), B + mid) - A.begin();

            if (R - L >= K) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        cout << low << '\n';
    }

    return 0;
}