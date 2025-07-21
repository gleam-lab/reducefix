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
        ll low = 0, high = 2e8 + 10; // Safe upper bound based on input limits
        ll answer = high;

        while (low <= high) {
            ll mid = (low + high) / 2;

            // Count how many points are within distance <= mid from b
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

        cout << answer << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}