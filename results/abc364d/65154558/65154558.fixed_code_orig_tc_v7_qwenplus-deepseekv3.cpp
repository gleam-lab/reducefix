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
        int low = 0, high = 2e8;
        ll ans = 0;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            auto left = lower_bound(A.begin(), A.end(), b - mid);
            auto right = upper_bound(A.begin(), A.end(), b + mid);
            int count = right - left;
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