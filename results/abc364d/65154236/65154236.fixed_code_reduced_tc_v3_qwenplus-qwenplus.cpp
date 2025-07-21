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

        // Binary search on distance
        ll low = 0, high = 2e8; // max possible distance is 2*1e8
        while (low < high) {
            ll mid = (low + high) / 2;
            // Count how many points have distance <= mid from b
            ll cnt = upper_bound(A.begin(), A.end(), b + mid) - lower_bound(A.begin(), A.end(), b - mid);
            if (cnt < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        cout << low << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}