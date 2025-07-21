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

    // Sort the A array to enable binary search
    sort(A.begin(), A.end());

    for (int q = 0; q < Q; ++q) {
        ll b;
        int k;
        cin >> b >> k;

        // Binary search on distance
        ll low = 0, high = 2e8 + 10; // Sufficiently large upper bound
        while (low < high) {
            ll mid = (low + high) / 2;

            // Count how many points have distance <= mid from b
            int cnt = 0;
            ll left = b - mid;
            ll right = b + mid;

            // Use lower_bound and upper_bound to count efficiently
            auto l = lower_bound(A.begin(), A.end(), left);
            auto r = upper_bound(A.begin(), A.end(), right);
            cnt = r - l;

            if (cnt >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        cout << low << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}