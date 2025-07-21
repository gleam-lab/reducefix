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
        ll low = 0, high = 2e8 + 10;
        ll answer = high;

        while (low <= high) {
            ll mid = (low + high) / 2;

            // Count how many points have distance <= mid from b
            int cnt = 0;
            ll left = b - mid;
            ll right = b + mid;

            // Use binary search to find range in sorted A
            auto l = lower_bound(A.begin(), A.end(), left);
            auto r = upper_bound(A.begin(), A.end(), right);

            int count = r - l;

            if (count >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << answer << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}