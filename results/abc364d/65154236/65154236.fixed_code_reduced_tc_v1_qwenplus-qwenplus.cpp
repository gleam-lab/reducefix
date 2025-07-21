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
    sort(A.begin(), A.end());

    for (int q = 0; q < Q; ++q) {
        ll b;
        int k;
        cin >> b >> k;

        // Binary search on the k-th smallest distance
        ll low = 0, high = 2e8; // max possible distance is <= 2*1e8
        ll answer = high;

        while (low <= high) {
            ll mid = (low + high) / 2;

            // Find how many points are in [b - mid, b + mid]
            int left = lower_bound(A.begin(), A.end(), b - mid) - A.begin();
            int right = upper_bound(A.begin(), A.end(), b + mid) - A.begin();
            int count = right - left;

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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}